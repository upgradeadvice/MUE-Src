MonetaryUnit 1.0.0.1 BETA
=====================

Copyright (c) 2009-2015 Bitcoin Developers
Copyright (c) 2014-2015 MonetaryUnit Developers


Setup
---------------------
[MonetaryUnit Core](http://monetaryunit.org/) is the original MonetaryUnit client and it builds the backbone of the network. However, it downloads and stores the entire history of MonetaryUnit transactions; depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md).

Running
---------------------
The following are some helpful notes on how to run MonetaryUnit on your native platform.

### Unix

You need the Qt4 run-time libraries to run MonetaryUnit-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/monetaryunit-qt (GUI, 32-bit) or bin/32/monetaryunitd (headless, 32-bit)
- bin/64/monetaryunit-qt (GUI, 64-bit) or bin/64/monetaryunitd (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run monetaryunit-qt.exe.

### OSX

Drag MonetaryUnit-Qt to your applications folder, and then run MonetaryUnit-Qt.

### Need Help?

* See the documentation at the [MonetaryUnit Wiki](https://en.monetaryunit.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#monetaryunit](http://webchat.freenode.net?channels=monetaryunit) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=monetaryunit).
* Ask for help on the [MonetaryUnitTalk](https://monetaryunittalk.org/) forums, in the [Technical Support board](https://monetaryunittalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build MonetaryUnit on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The MonetaryUnit repo's [root README](https://github.com/monetaryunit/MUE-Src/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on [#monetaryunit](http://webchat.freenode.net/?channels=monetaryunit) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=monetaryunit).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
