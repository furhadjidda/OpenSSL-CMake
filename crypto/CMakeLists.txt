
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(asn1)
include_directories(evp)
include_directories(modes)

file(GLOB SRCS

	aes/*.c
	aria/*.c
	asn1/*.c
	blake2/*.c
	bf/*.c
	bio/*.c
	bn/*.c
	buffer/*.c
	camellia/*.c
	cast/*.c
	cmac/*.c
	cms/*.c
	conf/*.c
	chacha/*.c
	dh/*.c

	des/*.c


	dsa/*.c
	dso/*.c

	ec/ec_lib.c
	ec/ecp_smpl.c
	ec/ecp_mont.c
	ec/ecp_nist.c
	ec/ec_cvt.c
	ec/ec_mult.c
	ec/ec_err.c
	ec/ec_curve.c
	ec/ec_check.c
	ec/ec_print.c
	ec/ec_asn1.c
	ec/ec_key.c
	ec/ec2_smpl.c
	ec/ec2_mult.c
	ec/ec_ameth.c
	ec/ec_pmeth.c
	ec/eck_prn.c
	ec/ecp_nistp224.c
	ec/ecp_nistp256.c
	ec/ecp_nistp521.c
	ec/ecp_nistputil.c
	ec/ecp_oct.c
	ec/ec2_oct.c
	ec/ec_oct.c
	ec/ec_kmeth.c
	ec/ecdh_ossl.c
	ec/ecdh_kdf.c
	ec/ecdsa_ossl.c
	ec/ecdsa_sign.c
	ec/ecdsa_vrf.c
	ec/curve25519.c
	ec/ecx_meth.c
	ec/curve448/arch_32/f_impl.c
	ec/curve448/f_generic.c
	ec/curve448/scalar.c
	ec/curve448/curve448_tables.c
	ec/curve448/eddsa.c
	ec/curve448/curve448.c

	sm2/*.c
	sm3/*.c
	sm4/*.c

    ecdsa/*.c
	ecdh/*.c
	err/*.c
	evp/*.c
	hmac/*.c
	idea/*.c
	kdf/*.c
	lhash/*.c
	md5/*.c
	modes/*.c
	objects/*.c
	ocsp/*.c
	pem/*.c
	pqueue/*.c
	pkcs7/*.c
	pkcs12/*.c
	poly1305/*.c
	rand/*.c
	rc2/*.c
	rc4/*.c
	ripemd/*.c
	rsa/*.c
	seed/*.c
	sha/*.c
	siphash/*.c
	srp/*.c
	stack/*.c
	store/*.c
	ts/*.c
	txt_db/*.c
	ui/*.c
	x509/*.c
	x509v3/*.c
	o_init.c o_fopen.c o_dir.c o_str.c o_time.c ex_data.c cpt_err.c cryptlib.c cversion.c

	ex_data.c

	init.c ctype.c

	uid.c

	async/async.c  async/async_err.c  async/async_wait.c

	mem.c mem_sec.c mem_dbg.c mem_clr.c
)

if (WIN32)
	set(THREAD_IMPL threads_win.c)
	set(ASYNC_ARCH_IMPL async/arch/async_win.c)
else()
	set(THREAD_IMPL threads_pthread.c)
	set(ASYNC_ARCH_IMPL async/arch/async_posix.c)
endif()

add_library(crypto_static STATIC ${SRCS} ${THREAD_IMPL} ${ASYNC_ARCH_IMPL})

set_target_properties(crypto_static PROPERTIES FOLDER "third_party/")

target_compile_definitions(crypto_static PUBLIC
	-DOPENSSL_NO_ASM
	-DOPENSSL_NO_ENGINE
	-DOPENSSL_NO_RC1
	-DOPENSSL_NO_RC3
	-DOPENSSL_NO_MD1
	-DOPENSSL_NO_MD2
	-DOPENSSL_NO_MD3
	-DOPENSSL_NO_MD4
	-DOPENSSL_NO_MDC2
	-DOPENSSL_NO_WHIRLPOOL
	-DOPENSSL_NO_COMP
	-DOPENSSL_NO_CT
	-DWIN32_LEAN_AND_MEAN
	-DOPENSSL_API_COMPAT=0x1010006fL)

target_include_directories(crypto_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/)
