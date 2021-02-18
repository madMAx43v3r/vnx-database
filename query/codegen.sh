#!/bin/bash

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ vnx.query interface/ ${1}/vnx/
