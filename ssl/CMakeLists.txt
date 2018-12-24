
set(SSL_SRC
	pqueue.c packet.c
	statem/statem_srvr.c statem/statem_clnt.c  s3_lib.c  s3_enc.c record/rec_layer_s3.c
	statem/statem_lib.c statem/extensions.c statem/extensions_srvr.c
	statem/extensions_clnt.c statem/extensions_cust.c s3_cbc.c s3_msg.c
	methods.c   t1_lib.c  t1_enc.c tls13_enc.c
	d1_lib.c  record/rec_layer_d1.c d1_msg.c
	statem/statem_dtls.c d1_srtp.c
	ssl_lib.c ssl_cert.c ssl_sess.c
	ssl_ciph.c ssl_stat.c ssl_rsa.c
	ssl_asn1.c ssl_txt.c ssl_init.c ssl_conf.c  ssl_mcnf.c
	bio_ssl.c ssl_err.c tls_srp.c t1_trce.c ssl_utst.c
	record/ssl3_buffer.c record/ssl3_record.c record/dtls1_bitmap.c
	statem/statem.c record/ssl3_record_tls13.c
)

include_directories(../crypto/)

add_library(eay32_static STATIC ${SSL_SRC})

target_link_libraries(eay32_static crypto_static)

set_target_properties(eay32_static PROPERTIES FOLDER "third_party/")

target_include_directories(eay32_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/)
