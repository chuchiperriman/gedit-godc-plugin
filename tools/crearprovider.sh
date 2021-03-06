#!/bin/sh
# Crea un provider a partir del provider test
namespace=GODC
mays=PROVIDER_FILE_BROWSER
type=GodcProviderFileBrowser
min=godc_provider_file_browser
file=godc-provider-file-browser

dest_dir=.

base_c=/home/perriman/dev/gtksourceview/tests/gsc-provider-test.c
base_h=/home/perriman/dev/gtksourceview/tests/gsc-provider-test.h

com="s/PROVIDER_TEST/$mays/g;s/GSC/$namespace/g;s/GscProviderTest/$type/g"
com="$com;s/gsc_provider_test/$min/g;s/gsc-provider-test/$file/g"
com="$com;s/__TEST_PROVIDER_H__/__${mays}_H__/g;s/gsc-provider-test/$file/g"

sed $com $base_c > $dest_dir/$file.c
sed $com $base_h > $dest_dir/$file.h
