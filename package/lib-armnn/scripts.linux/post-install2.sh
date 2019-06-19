#!/bin/bash

#
# See CK LICENSE.txt for licensing details.
# See CK COPYRIGHT.txt for copyright details.
#
# Developer(s):
# - Anton Lokhmotov, 2019
#

function exit_if_error() {
    if [ "${?}" != "0" ]; then exit 1; fi
}

# A workaround for an ArmNN v19.05 issue: https://github.com/ARM-software/armnn/issues/196
if [ "$USE_TFLITE" == "YES" ] && [ "$PACKAGE_VERSION" == "19.05" ]
then
    echo ""
    echo "Copying 'libarmnnTfLiteParser${CK_DLL_EXT}' to '${INSTALL_DIR}/install/lib' ..."
    cp ${INSTALL_DIR}/obj/libarmnnTfLiteParser${CK_DLL_EXT} ${INSTALL_DIR}/install/lib/
    exit_if_error
fi
