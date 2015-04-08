AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS)


if EMBEDDED_LEVELDB
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/include
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/helpers/memenv
LIBLEVELDB += $(builddir)/leveldb/libleveldb.a
LIBMEMENV  += $(builddir)/leveldb/libmemenv.a

# NOTE: This dependency is not strictly necessary, but without it make may try to build both in parallel, which breaks the LevelDB build system in a race
$(LIBLEVELDB): $(LIBMEMENV)

$(LIBLEVELDB) $(LIBMEMENV):
	@echo "Building LevelDB ..." && $(MAKE) -C $(@D) $(@F) CXX="$(CXX)" \
	  CC="$(CC)" PLATFORM=$(TARGET_OS) AR="$(AR)" $(LEVELDB_TARGET_FLAGS) \
          OPT="$(CXXFLAGS) $(CPPFLAGS)"
endif

MONETARYUNIT_CONFIG_INCLUDES=-I$(builddir)/config
MONETARYUNIT_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

LIBMONETARYUNIT_SERVER=libmonetaryunit_server.a
LIBMONETARYUNIT_WALLET=libmonetaryunit_wallet.a
LIBMONETARYUNIT_COMMON=libmonetaryunit_common.a
LIBMONETARYUNIT_CLI=libmonetaryunit_cli.a
LIBMONETARYUNITQT=qt/libmonetaryunitqt.a

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES = \
  libmonetaryunit_server.a \
  libmonetaryunit_common.a \
  libmonetaryunit_cli.a
if ENABLE_WALLET
MONETARYUNIT_INCLUDES += $(BDB_CPPFLAGS)
EXTRA_LIBRARIES += libmonetaryunit_wallet.a
endif

bin_PROGRAMS =
TESTS =

if BUILD_MONETARYUNITD
  bin_PROGRAMS += monetaryunitd
endif

if BUILD_MONETARYUNIT_CLI
  bin_PROGRAMS += monetaryunit-cli
endif

.PHONY: FORCE
# monetaryunit core #
MONETARYUNIT_CORE_H = \
  addrman.h \
  alert.h \
  allocators.h \
  base58.h bignum.h \
  bloom.h \
  chainparams.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  core.h \
  crypter.h \
  db.h \
  hash.h \
  hashblock.h \
  sph_types.h \
  sph_blake.h \
  sph_bmw.h \
  sph_groestl.h \
  sph_jh.h \
  sph_keccak.h \
  sph_skein.h \
  init.h \
  key.h \
  keystore.h \
  leveldbwrapper.h \
  limitedmap.h \
  main.h \
  miner.h \
  mruset.h \
  netbase.h \
  net.h \
  noui.h \
  protocol.h \
  rpcclient.h \
  rpcprotocol.h \
  rpcserver.h \
  script.h \
  serialize.h \
  sync.h \
  threadsafety.h \
  tinyformat.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  uint256.h \
  util.h \
  version.h \
  walletdb.h \
  wallet.h

JSON_H = \
  json/json_spirit.h \
  json/json_spirit_error_position.h \
  json/json_spirit_reader.h \
  json/json_spirit_reader_template.h \
  json/json_spirit_stream_reader.h \
  json/json_spirit_utils.h \
  json/json_spirit_value.h \
  json/json_spirit_writer.h \
  json/json_spirit_writer_template.h

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libmonetaryunit_common_a-version.$(OBJEXT): obj/build.h


libmonetaryunit_server_a_CPPFLAGS = $(MONETARYUNIT_INCLUDES) $(MINIUPNPC_CPPFLAGS)
libmonetaryunit_server_a_SOURCES = \
  addrman.cpp \
  alert.cpp \
  bloom.cpp \
  checkpoints.cpp \
  coins.cpp \
  init.cpp \
  keystore.cpp \
  leveldbwrapper.cpp \
  main.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  rpcblockchain.cpp \
  rpcmining.cpp \
  rpcmisc.cpp \
  rpcnet.cpp \
  rpcrawtransaction.cpp \
  rpcserver.cpp \
  txdb.cpp \
  txmempool.cpp \
  $(JSON_H) \
  $(MONETARYUNIT_CORE_H)

libmonetaryunit_wallet_a_CPPFLAGS = $(MONETARYUNIT_INCLUDES)
libmonetaryunit_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  walletdb.cpp \
  $(MONETARYUNIT_CORE_H)

libmonetaryunit_common_a_CPPFLAGS = $(MONETARYUNIT_INCLUDES) -fPIC
libmonetaryunit_common_a_SOURCES = \
  base58.cpp \
  allocators.cpp \
  chainparams.cpp \
  core.cpp \
  hash.cpp \
  blake.c \
  bmw.c \
  groestl.c \
  jh.c \
  keccak.c \
  skein.c \
  key.cpp \
  netbase.cpp \
  protocol.cpp \
  rpcprotocol.cpp \
  script.cpp \
  sync.cpp \
  util.cpp \
  version.cpp \
  $(MONETARYUNIT_CORE_H)

if GLIBC_BACK_COMPAT
libmonetaryunit_common_a_SOURCES += compat/glibc_compat.cpp
endif

libmonetaryunit_cli_a_CPPFLAGS = $(MONETARYUNIT_INCLUDES)
libmonetaryunit_cli_a_SOURCES = \
  rpcclient.cpp \
  $(MONETARYUNIT_CORE_H)

nodist_libmonetaryunit_common_a_SOURCES = $(top_srcdir)/src/obj/build.h
#

# monetaryunitd binary #
monetaryunitd_SOURCES = monetaryunitd.cpp
monetaryunitd_CPPFLAGS = $(MONETARYUNIT_INCLUDES)
monetaryunitd_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
monetaryunitd_SOURCES += monetaryunitd-res.rc
endif

monetaryunitd_LDADD = \
  $(LIBMONETARYUNIT_SERVER) \
  $(LIBMONETARYUNIT_COMMON) \
  $(LIBMONETARYUNIT_CLI) \
  $(LIBLEVELDB) \
  $(LIBMEMENV)

if ENABLE_WALLET
monetaryunitd_LDADD += libmonetaryunit_wallet.a
endif

monetaryunitd_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS)
#

# monetaryunit-cli binary #
monetaryunit_cli_SOURCES = monetaryunit-cli.cpp
monetaryunit_cli_CPPFLAGS = $(MONETARYUNIT_INCLUDES)
monetaryunit_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
monetaryunit_cli_SOURCES += monetaryunit-cli-res.rc
endif

monetaryunit_cli_LDADD = \
  $(LIBMONETARYUNIT_CLI) \
  $(LIBMONETARYUNIT_COMMON)

monetaryunit_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS)
#

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a *.gcda *.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb

clean-local:
	-$(MAKE) -C leveldb clean
	rm -f leveldb/*/*.gcno leveldb/helpers/memenv/*.gcno
	-rm -f config.h

.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
