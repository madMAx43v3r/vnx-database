#!/bin/bash

export VNX_INTERFACE_DIR=${VNX_INTERFACE_DIR:-/usr/interface}

cd $(dirname "$0")

./query/codegen.sh ${VNX_INTERFACE_DIR}

vnxcppcodegen --cleanup generated/ vnx.database interface/ modules/ ${VNX_INTERFACE_DIR}/vnx/ query/interface/
