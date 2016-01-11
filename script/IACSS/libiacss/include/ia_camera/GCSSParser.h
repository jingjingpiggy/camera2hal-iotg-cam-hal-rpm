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

#ifndef __GCSS_PARSER_H__
#define __GCSS_PARSER_H__

#include "graph_query_manager.h"

namespace GCSS {

/**
 * \class GCSSParser
 *
 * This class is used to parse the Graph Configuration Subsystem graph
 * descriptor xml file. Uses the expat lib to do the parsing.
 */
class GCSSParser {
public:
    GCSSParser(){};
    ~GCSSParser();
    void parseGCSSXmlFile(const char*, GraphConfigNode**);

private: /* Constants*/
    static const int BUFFERSIZE = 4*1024;  // For xml file

private: /* Methods */
    static void startElement(void *userData, const char *name, const char **atts);
    static void endElement(void *userData, const char *name);

    void getElementType(const ItemUID& att_uid, ia_uid& data_type);
    void handleGraph(const char *name, const char **atts);
    void handleNode(const char *name, const char **atts);
    void checkField(GCSSParser *profiles, const char *name, const char **atts);

private:  /* Members */

    GCSS::GraphConfigNode *mCurrentNode; /* TODO: these should be of GraphConfig-iface type */
};
} // namespace
#endif
