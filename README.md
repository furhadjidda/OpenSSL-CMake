
openssl - cmake build 
not full ssl functionality but mostly works.


*HOW TO USE*

adding lines to cmakelists.txt


```

find_package(OpenSSL)

if (NOT OpenSSL_FOUND)
	add_subdirectory(3rd/openssl-cmake)
	set(OPENSSL_LIBRARIES crypto_static eay32_static)
else()
	set(OPENSSL_LIBRARIES OpenSSL::Crypto OpenSSL::SSL)
endif()

```
