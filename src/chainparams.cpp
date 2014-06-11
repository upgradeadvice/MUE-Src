// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 Bitcoin Developers
// Copyright (c) 2014-2015 MonetaryUnit Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>
#include <stdint.h>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0x01020304,
};

static const unsigned int timeMainGenesisBlock = 1404668200;
uint256 hashMainGenesisBlock("0x0000070e6b650e7a6f20e015031b74c1f7e2b25ed4e419d8825ab9cc7eccfa92");
static CBigNum bnMainProofOfWorkLimit(~uint256(0) >> 20);

static const int64_t nGenesisBlockRewardCoin = 0 * COIN;
static const int64_t nBlockRewardStartCoin = 40 * COIN;
static const int64_t nBlockRewardMinimumCoin = 1 * COIN;

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x04;
        pchMessageStart[1] = 0x05;
        pchMessageStart[2] = 0x05;
        pchMessageStart[3] = 0x04;
        vAlertPubKey = ParseHex("044160a269d0250990b4517566b47e24d2a94ba458edfe856d4a63c9c62cc3aa6354cddbc9371313af65616675fa009ab13aac2bb0f5ce6bf7b8e91861765144dc");
        nDefaultPort = 29948;
        nRPCPort = 29947;
        bnProofOfWorkLimit = bnMainProofOfWorkLimit;
        //nSubsidyHalvingInterval = 2147483647;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        const char* pszTimestamp = "M O N E T A R Y U N I T";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = nGenesisBlockRewardCoin;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 112;
        genesis.nTime    = timeMainGenesisBlock + 5;
        genesis.nBits    = bnMainProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 139785;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == hashMainGenesisBlock);
        assert(genesis.hashMerkleRoot == uint256("0xa2cc3c1d8ab6e50e80464693199eefdd172d45c4129998394e636e47b5621364"));

        vSeeds.push_back(CDNSSeedData("dnsseed.monetaryunit.tk", "dnsseed.monetaryunit.tk"));
        vSeeds.push_back(CDNSSeedData("dnsseed2.monetaryunit.tk", "dnsseed2.monetaryunit.tk"));
        // vSeeds.push_back(CDNSSeedData("103.19.252.82", "103.19.252.82"));
        // vSeeds.push_back(CDNSSeedData("178.62.247.76", "178.62.247.76"));
        // vSeeds.push_back(CDNSSeedData("104.131.66.88", "104.131.66.88"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(15);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(9);
        base58Prefixes[SECRET_KEY] =     list_of(143);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x01;
        pchMessageStart[1] = 0x1A;
        pchMessageStart[2] = 0x39;
        pchMessageStart[3] = 0xF7;
        vAlertPubKey = ParseHex("04f98a3941171ec7de8b83593aa6f7459a7605fb055c3e82c330ef89e7a46b78efeaa1e15580dddf694cf668fcc57b3aa0a47555e33aa7b0cb86ef6393975dc8f4");
        nDefaultPort = 39948;
        nRPCPort = 39947;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = timeMainGenesisBlock + 5;
        genesis.nNonce = 139785;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000070e6b650e7a6f20e015031b74c1f7e2b25ed4e419d8825ab9cc7eccfa92"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = list_of(119);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(199);
        base58Prefixes[SECRET_KEY]     = list_of(247);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        //nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        //assert(hashGenesisBlock == uint256("0x0000070e6b650e7a6f20e015031b74c1f7e2b25ed4e419d8825ab9cc7eccfa92"));
        assert(hashGenesisBlock == hashGenesisBlock);
        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
