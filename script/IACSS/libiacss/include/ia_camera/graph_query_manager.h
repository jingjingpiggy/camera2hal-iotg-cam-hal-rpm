/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2015 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */

#ifndef GRAPH_QUERY_MANAGER_H
#define GRAPH_QUERY_MANAGER_H

#include <string>
#include <map>
#include <utility>
#include <vector>
#include <ia_tools/ia_types.h>
#include <ia_cipf/ia_cipf_types.h>

/**
 * Todo: Dynamically replace XML Node tags with its name
 */

namespace GCSS {

class ItemUID
{
public:
    static ia_uid str2key(const std::string&);
    static const char* key2str(const ia_uid key);
    static ia_uid generateKey(const std::string&);
    static void addCustomKeyMap(std::map<std::string, ia_uid> &osMap);

    ItemUID(std::initializer_list<ia_uid> uids) {
        mUids.insert(mUids.end(), uids.begin(), uids.end());
    };
    ItemUID() {};
    void pop_back() { mUids.pop_back(); };
    void push_back( const ia_uid& iuid) { mUids.push_back(iuid); };

    bool operator == (const ItemUID& v) const {
        return v.mUids == mUids;
    }
    std::string toString() const;

    std::size_t size() const { return mUids.size(); };

    ItemUID(const ItemUID &ref) { mUids = ref.mUids; };

    ia_uid& operator[](std::size_t idx) { return mUids[idx]; }
    const ia_uid& operator[](std::size_t idx) const
    { return mUids[idx]; }

private:
    friend bool operator<(const ItemUID &r, const ItemUID &l);
    friend bool operator>(const ItemUID &r, const ItemUID &l);
    std::vector<ia_uid> mUids;

};

inline bool operator<(const ItemUID &r, const ItemUID &l)
{
    return r.mUids < l.mUids;
}

inline bool operator>(const ItemUID &r, const ItemUID &l)
{
    return r.mUids > l.mUids;
}

/**
 * Holds type of the item. It can be Node or Attribute (int or string)
 */
enum Type {
    NA,
    STR_ATTRIBUTE,
    INT_ATTRIBUTE,
    NODE
};

// CONTAINER FOR ATTRIBUTE OR LEAF
class GraphConfigItem
{
public:
    typedef std::multimap<ia_uid, GraphConfigItem*> gcss_item_map;
    typedef gcss_item_map::const_iterator const_iterator;
    GraphConfigItem::const_iterator getNext(const_iterator& it){
                                            return std::next(it, 1);}
    /* Return error if getValue is being used directly or if child class
     * doesn't implement getValue */
    virtual ia_err_t getValue(int&) {return ia_err_noentry;}
    virtual ia_err_t getValue(std::string&) {return ia_err_noentry;}
    Type type;
    GraphConfigItem(Type type) : type(type) {}

    virtual ~GraphConfigItem() {}
};

class GraphConfigAttribute : public GraphConfigItem {
public:
    GraphConfigAttribute() : GraphConfigItem(NA){}
    GraphConfigAttribute(Type t) : GraphConfigItem(t){}
    ~GraphConfigAttribute() {}
};

/**
 * Container for integer type attributes
 */
class GraphConfigIntAttribute : public GraphConfigAttribute
{
public:
    GraphConfigIntAttribute() : GraphConfigAttribute(INT_ATTRIBUTE), mInteger(-1){}
    GraphConfigIntAttribute* copy();
    ia_err_t insertInteger(int);
    ia_err_t getInteger(int&);
    ia_err_t getValue(int& intVal){intVal = mInteger; return ia_err_none;}
    ia_err_t getAttrValAsString(std::string &ret);
    ~GraphConfigIntAttribute() {};
private:
    int mInteger;
};

/**
 * Container for string type attributes
 */
class GraphConfigStrAttribute : public GraphConfigAttribute
{
public:
    GraphConfigStrAttribute() : GraphConfigAttribute(STR_ATTRIBUTE){}
    GraphConfigStrAttribute* copy();
    ia_err_t insertString(const std::string&);
    ia_err_t getString(std::string&);
    ia_err_t getValue(std::string& str){str = mString; return ia_err_none;}
    ~GraphConfigStrAttribute() {};
private:
    std::string mString;
};

// LEAF
class GraphConfigNode : public GraphConfigItem
{
public:
    typedef std::vector<GraphConfigNode*> gcss_node_vector;

    GraphConfigNode(const GraphConfigNode&);
    GraphConfigNode() : GraphConfigItem(NODE), mAncestor(NULL){};
    ~GraphConfigNode();

    GraphConfigNode* copy();
    gcss_item_map item;
    void dumpNode();
    static void dumpNodeTree(GraphConfigNode*, int depth  = 0);
    const_iterator begin() const { return item.begin(); }
    const_iterator end() const { return item.end(); }
    ia_err_t getAllDescendants(gcss_node_vector&) const;
    ia_err_t getAncestor(GraphConfigNode**);
    ia_err_t getAttribute(const ia_uid iuid, GraphConfigAttribute** ret) const;
    ia_err_t getIntAttribute(const ia_uid, GraphConfigIntAttribute&);
    ia_err_t getStrAttribute(const ia_uid, GraphConfigStrAttribute&);
    ia_err_t getDescendant(const ia_uid, GraphConfigNode**) const;
    ia_err_t getDescendant(const ia_uid attribute,
                           const int searchAttributeValue,
                           const_iterator& it,
                           GraphConfigNode** retNode) const;
    ia_err_t getDescendant(const ia_uid attribute,
                           const std::string& searchAttributeValue,
                           const_iterator& it,
                           GraphConfigNode** retNode) const;
    ia_err_t getNodeCountByType(const std::string &typeValue, uint32_t& count);
    ia_err_t getDescendantByString(const std::string &str,
                                   GraphConfigNode **retNode);
    ia_err_t insertDescendant(GraphConfigItem*, const ia_uid);
    ia_err_t getConnectionData(const std::string& connection_string,
                               const GraphConfigNode* settings,
                               GraphConfigNode* ret_node,
                               std::vector<ia_uid>& addedNodesVector);
    template <typename T>
    ia_err_t getValue(const ia_uid& uid, T& val) const {

        GraphConfigAttribute * retAttribute;
        ia_err_t ret = getAttribute(uid, &retAttribute);

        if (ia_err_none != ret)
            return ret;

        return retAttribute->getValue(val);
    }
private:
    /**
     * Helper function which iterates through given node and search for
     * matching attribute. Return error if not found.
     * \param attribute the ItemUID of attribute to search
     * \param searchAttributeValue the value to search
     * \param it iterator for the node to search
     * \return ia_err_t
     */
    template <typename T>
    ia_err_t iterateAttributes(ia_uid attribute,
                               const T& searchAttributeValue,
                               const const_iterator& it) const
    {
        GraphConfigNode * node = static_cast<GraphConfigNode*>(it->second);
        const_iterator attrIterator = node->begin();

        while (attrIterator != node->end()) {
            if (attrIterator->first == attribute) {
                GraphConfigAttribute * retAttr =
                    static_cast<GraphConfigAttribute*>(attrIterator->second);
                T foundAttrValue;
                ia_err_t ret = retAttr->getValue(foundAttrValue);

                if (ret != ia_err_none)
                    return ret;
                if (foundAttrValue == searchAttributeValue)
                    return ia_err_none;
            }
            attrIterator = node->getNext(attrIterator); // Get a next attribute
        }
        return ia_err_end;
    }

    ia_err_t addDescendantsFromNode(GraphConfigNode*);
    ia_err_t addResInfo(const GraphConfigNode* settings);
    GraphConfigItem::const_iterator getNextAttribute(
            GraphConfigItem::const_iterator& it) const;
    GraphConfigNode* mAncestor;
};

class GraphQueryManager : public GraphConfigNode
{
public:
    typedef std::vector<GraphConfigNode*> GraphQueryResult;
    typedef std::map<ItemUID, std::string> GraphQuery;

    ia_err_t getGraph(GraphConfigNode*, GraphConfigNode*);
    ia_err_t queryGraphs(const GraphQuery&,
                         GraphQueryResult&,
                         bool strict = true);
    ia_err_t queryGraphs(const GraphQuery&,
                         const GraphQueryResult&,
                         GraphQueryResult&,
                         bool strict = true);
    void setGraphSettings(const GraphConfigNode* settings) {mGraphSettings = settings;}
    void setGraphDescriptor(const GraphConfigNode* descriptor) {mGraphDescriptor = descriptor;}
private:
    // true = every search item has to match, false = at least one match
    bool strictQuery;
    // Store parsed data into these containers, instead of using a single node
    const GraphConfigNode* mGraphSettings;
    const GraphConfigNode* mGraphDescriptor;
    ItemUID iuidVector; // Contains sequence of keys to find a certain item

    ia_err_t goThroughSettings(const GraphQuery&,
                               const GraphQueryResult&,
                               GraphQueryResult&);
    ia_err_t goThroughSearchItems(const GraphQuery&, GraphConfigNode*, uint16_t&);
    static ia_err_t findNodeByID(int, GraphConfigNode*, GraphConfigNode**);
    static std::vector<std::string> splitStringAtColon(const std::string&);
};
} // namespace
#endif
