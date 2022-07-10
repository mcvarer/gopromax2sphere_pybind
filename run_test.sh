#!/bin/bash

set -e

(git submodule update --init --recursive)
(python -m pip install -U . )

rm -rf "./stubs/generated"

(coverage run -m pybind11_stubgen maxsphere \
           --output-dir="./stubs/generated" \
           --root-module-suffix="" \
           --ignore-invalid=all \
           --no-setup-py || exit 0)
