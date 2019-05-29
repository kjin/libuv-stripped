rm -rf gyp
git clone https://chromium.googlesource.com/external/gyp
pushd gyp
rm -rf .git buildbot data samples test tools
popd

rm -rf libuv
git clone https://github.com/libuv/libuv
pushd libuv
rm -rf .git .github docs img m4 samples test tools
popd
