include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = monetaryunit-qt
noinst_LIBRARIES = libmonetaryunitqt.a
SUBDIRS = . $(BUILD_TEST_QT)
DIST_SUBDIRS = . test

# monetaryunit qt core #
QT_TS = \
  locale/monetaryunit_ach.ts \
  locale/monetaryunit_af_ZA.ts \
  locale/monetaryunit_ar.ts \
  locale/monetaryunit_be_BY.ts \
  locale/monetaryunit_bg.ts \
  locale/monetaryunit_bs.ts \
  locale/monetaryunit_ca_ES.ts \
  locale/monetaryunit_ca.ts \
  locale/monetaryunit_ca@valencia.ts \
  locale/monetaryunit_cmn.ts \
  locale/monetaryunit_cs.ts \
  locale/monetaryunit_cy.ts \
  locale/monetaryunit_da.ts \
  locale/monetaryunit_de.ts \
  locale/monetaryunit_el_GR.ts \
  locale/monetaryunit_en.ts \
  locale/monetaryunit_eo.ts \
  locale/monetaryunit_es_CL.ts \
  locale/monetaryunit_es_DO.ts \
  locale/monetaryunit_es_MX.ts \
  locale/monetaryunit_es.ts \
  locale/monetaryunit_es_UY.ts \
  locale/monetaryunit_et.ts \
  locale/monetaryunit_eu_ES.ts \
  locale/monetaryunit_fa_IR.ts \
  locale/monetaryunit_fa.ts \
  locale/monetaryunit_fi.ts \
  locale/monetaryunit_fr_CA.ts \
  locale/monetaryunit_fr.ts \
  locale/monetaryunit_gl.ts \
  locale/monetaryunit_gu_IN.ts \
  locale/monetaryunit_he.ts \
  locale/monetaryunit_hi_IN.ts \
  locale/monetaryunit_hr.ts \
  locale/monetaryunit_hu.ts \
  locale/monetaryunit_id_ID.ts \
  locale/monetaryunit_it.ts \
  locale/monetaryunit_ja.ts \
  locale/monetaryunit_ka.ts \
  locale/monetaryunit_kk_KZ.ts \
  locale/monetaryunit_ko_KR.ts \
  locale/monetaryunit_ky.ts \
  locale/monetaryunit_la.ts \
  locale/monetaryunit_lt.ts \
  locale/monetaryunit_lv_LV.ts \
  locale/monetaryunit_mn.ts \
  locale/monetaryunit_ms_MY.ts \
  locale/monetaryunit_nb.ts \
  locale/monetaryunit_nl.ts \
  locale/monetaryunit_pam.ts \
  locale/monetaryunit_pl.ts \
  locale/monetaryunit_pt_BR.ts \
  locale/monetaryunit_pt_PT.ts \
  locale/monetaryunit_ro_RO.ts \
  locale/monetaryunit_ru.ts \
  locale/monetaryunit_sah.ts \
  locale/monetaryunit_sk.ts \
  locale/monetaryunit_sl_SI.ts \
  locale/monetaryunit_sq.ts \
  locale/monetaryunit_sr.ts \
  locale/monetaryunit_sv.ts \
  locale/monetaryunit_th_TH.ts \
  locale/monetaryunit_tr.ts \
  locale/monetaryunit_uk.ts \
  locale/monetaryunit_ur_PK.ts \
  locale/monetaryunit_uz@Cyrl.ts \
  locale/monetaryunit_vi.ts \
  locale/monetaryunit_vi_VN.ts \
  locale/monetaryunit_zh_CN.ts \
  locale/monetaryunit_zh_HK.ts \
  locale/monetaryunit_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/miningpage.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_monetaryunitaddressvalidator.cpp \
  moc_monetaryunitamountfield.cpp \
  moc_monetaryunitgui.cpp \
  moc_monetaryunitunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp \
  moc_miningpage.cpp

MONETARYUNIT_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  monetaryunit.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_monetaryunit.cpp
QT_QRC = monetaryunit.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

MONETARYUNIT_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  monetaryunitaddressvalidator.h \
  monetaryunitamountfield.h \
  monetaryunitgui.h \
  monetaryunitunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h \
  winshutdownmonitor.h \
  miningpage.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/monetaryunit.ico \
  res/icons/monetaryunit.png \
  res/icons/monetaryunit_testnet.ico \
  res/icons/monetaryunit_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

MONETARYUNIT_QT_CPP = \
  monetaryunit.cpp \
  monetaryunitaddressvalidator.cpp \
  monetaryunitamountfield.cpp \
  monetaryunitgui.cpp \
  monetaryunitunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp \
  winshutdownmonitor.cpp

if ENABLE_WALLET
MONETARYUNIT_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  sendcoinsentry.cpp \
  signverifymessagedialog.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp \
  miningpage.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png \
  res/images/bg.png \
  res/images/qbg.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

MONETARYUNIT_RC = res/monetaryunit-qt-res.rc

libmonetaryunitqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libmonetaryunitqt_a_SOURCES = $(MONETARYUNIT_QT_CPP) $(MONETARYUNIT_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libmonetaryunitqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libmonetaryunitqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# monetaryunit-qt binary #
monetaryunit_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
monetaryunit_qt_SOURCES = monetaryunit.cpp
if TARGET_DARWIN
  monetaryunit_qt_SOURCES += $(MONETARYUNIT_MM)
endif
if TARGET_WINDOWS
  monetaryunit_qt_SOURCES += $(MONETARYUNIT_RC)
endif
monetaryunit_qt_LDADD = libmonetaryunitqt.a $(LIBMONETARYUNIT_SERVER)
if ENABLE_WALLET
monetaryunit_qt_LDADD += $(LIBMONETARYUNIT_WALLET)
endif
monetaryunit_qt_LDADD += $(LIBMONETARYUNIT_CLI) $(LIBMONETARYUNIT_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
monetaryunit_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

monetaryunitstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/monetaryunitstrings.cpp

translate: monetaryunitstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(MONETARYUNIT_QT_CPP) $(MONETARYUNIT_QT_H) $(MONETARYUNIT_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/monetaryunit_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name monetaryunit -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -e '/^\*\*.*Created:/d' $@ > $@.n && mv $@{.n,}
	$(SED) -e '/^\*\*.*by:/d' $@  > $@.n && mv $@{.n,}

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
