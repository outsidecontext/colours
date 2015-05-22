#!/bin/bash

# Clones dependencies
# !Run this script from the Mumm project root!

# cd ../../addons/

# create new addons dir
# mkdir addons
cd ../../addons

# passing no arguments means read only
if [ -z $1 ]; then
    CLONE="git clone https://github.com/"
    echo "Cloning read-only"
else
    CLONE="git clone git@github.com:"
    echo "Cloning writable"
fi

# git clone specific revision of the addons
${CLONE}jmarsico/ofxImageSampler
# cd ofxUI
# git checkout 1f524f2c41c73113c7529703e6f3274fdcc19956
# cd ..


# final step is to cd back to the start dir
cd ..