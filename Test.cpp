#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace phonetic;

// i have used this site to find word's of diffrent length from 1 to 15 
//https://wordfinder.yourdictionary.com/words-with-the-letter/w/

TEST_CASE("Test replacement of v and w") {
    string text = "ve we saw  when poVder grown powder groVing growing reviewed Vhen Sav somewhere  somewhere dishwasher  answerphone . Israel has evidence of the earliest migration of hominids out of Africa.[28] Canaanite tribes are archaeologically attested since the Middle Bronze Age,[29][30] while the Kingdoms of Israel and Judah emerged during the Iron Age.[31][32] The Neo-Assyrian Empire destroyed Israel around 720 BCE.[33] Judah was later conquered by the Babylonian, Persian and Hellenistic empires and had existed as Jewish autonomous provinces.[34][35] The successful Maccabean Revolt led to an independent Hasmonean kingdom by 110 BCE,[36] which in 63 BCE however became a client state of the Roman Republic that subsequently installed the Herodian dynasty in 37 BCE, and in 6 CE created the Roman province of Judea.[37] Judea lasted as a Roman province until the failed Jewish revolts resulted in widespread destruction,[36] the expulsion of the Jewish population[36][38] and the renaming of the region from Iudaea to Syria Palaestina.[39] Jewish presence in the region has persisted to a certain extent over the centuries. In the 7th century CE, the Levant was taken from the Byzantine Empire by the Arabs and";
    CHECK(find(text, "we") == string("ve"));
    CHECK(find(text, "ve") == string("we"));
    CHECK(find(text, "saw") == string("Sav"));
    CHECK(find(text, "when") == string("Vhen"));
    CHECK(find(text, "while") == string("while"));
    CHECK(find(text, "powder") == string("powder"));
    CHECK(find(text, "powder") == string("poVder"));
    CHECK(find(text, "growing") == string("groVing"));
    CHECK(find(text, "growing") == string("groVing"));
    CHECK(find(text, "somewhere") == string("someVhere"));

}

TEST_CASE("Test replacement of b and p") {
    string text = "Bacteriologically  blasphemousnesses  biostatisticians   Beatification beatification   Blasphemousnesses Breakthrough Breathtaking broadcasting  bacchanalian bachelorette";
    CHECK(find(text, "bacteriologically") == string("Bacteriologically"));
    CHECK(find(text, "bacteriologically") == string("bacteriologically"));
    CHECK(find(text, "bacteriologically") == string("Pacteriologically"));
    CHECK(find(text, "bacteriologically") == string("pacteriologically"));
    CHECK(find(text, "breathtaking") == string("Bacteriologically"));
    CHECK(find(text, "breathtaking") == string("Breathtaking"));
    CHECK(find(text, "bacchanalian") == string("Bacchanalian"));
    CHECK(find(text, "blasphemousnesses") == string("Blasphemousnesses"));
    CHECK(find(text, "beatification") == string("beatification"));
    CHECK(find(text, "beatification") == string("beatification"));
    CHECK(find(text, "breathtaking") == string("Bacteriologically"));
    CHECK(find(text, "bacchanalian") == string("bacchanalian"));


}



TEST_CASE("Test replacement of f and p") {
    string text = " difficulties antiferromagnetically  antiFerromagnetically  personifications conPigurations antiPerromagnetically antiFerromagnetically  crestPallennesses   crestfallennesses antiferromagnetism disgracefulnesses  crestfallennesses personifications confidentiality identification  configurations  significantly professional  ";
            CHECK(find(text, "antiferromagnetically") == string("antiferromagnetically"));
            CHECK(find(text, "antiferromagnetically") == string("antiFerromagnetically"));
            CHECK(find(text, "antiferromagnetically") == string("antiFerromagnetically"));
            CHECK(find(text, "antiferromagnetically") == string("antiPerromagnetically"));
            CHECK(find(text, "crestfallennesses") == string("crestfallennesses"));
            CHECK(find(text, "crestfallennesses") == string("crestfallennesses"));
            CHECK(find(text, "configurations") == string("conPigurations"));
            CHECK(find(text, "personifications") == string("personifications"));
            CHECK(find(text, "personifications") == string("personiPications"));
            CHECK(find(text, "difficulties") == string("difficulties"));
            CHECK(find(text, "difficulties") == string("diPPficulties"));
            CHECK(find(text, "difficulties") == string("difPiculties"));
}


TEST_CASE("Test replacement of c and k") {
    string text = "acknowledgements accnowledgements akknowledgements uncccknowledgeable pharmacokinetics unknowledgeable unknowledgeable pharmakokinetic  pharmacokinetic cholecystokinins counterblockades  counterblockades counterattackers counterblockaded ";
            CHECK(find(text, "acknowledgements") == string("acknowledgements"));
            CHECK(find(text, "acknowledgements") == string("accnowledgements"));
            CHECK(find(text, "acknowledgements") == string("acknowledgements"));
            CHECK(find(text, "pharmacokinetic") == string("pharmacokinetic"));
            CHECK(find(text, "pharmacokinetic") == string("pharmacokinetic"));
            CHECK(find(text, "acknowledgements") == string("acknowledgements"));
            CHECK(find(text, "acknowledgements") == string("acknowledgements"));
            CHECK(find(text, "unkkkknowledgeable") == string("unkkkknowledgeable"));
            CHECK(find(text, "pharmacokinetic") == string("pharmacokinetic"));

}



TEST_CASE("Test replacement of  c , k and q") {
    string text = "inconsequentialities inconsequentialities counterkuestionink  ackuisitivenesses inconsekuentiality  acquisitivenesses counterquestioned  inconsequentially  inquisitivenesses picturesquenesses  disequilibrium  quarrelsomenesses  ";
            CHECK(find(text, "inconsequentialities") == string("inconsequentialities"));
            CHECK(find(text, "inconsekuentiality") == string("inconsekuentiality"));
            CHECK(find(text, "inconsequentiality") == string("inconsekuentiality"));
            CHECK(find(text, "acquisitivenesses") == string("acquisitivenesses"));
            CHECK(find(text, "acquisitivenesses") == string("acquisitivenesses"));
            CHECK(find(text, "inconsequentiality") == string("inconsequentially"));
            CHECK(find(text, "inconsekuentially") == string("inconsequentially"));
            CHECK(find(text, "inconsekuentiality") == string("inconsekuentiality"));
            CHECK(find(text, "inconsequentiality") == string("inconsekuentiality"));

            CHECK(find(text, "inKonsequentialities") == string("inconsequentialities"));
            CHECK(find(text, "inkonsekuentiality") == string("inconsekuentiality"));
            CHECK(find(text, "inqonsequentiality") == string("inconsekuentiality"));
            CHECK(find(text, "accuisitivenesses") == string("acquisitivenesses"));
            CHECK(find(text, "ackuisitivenesses") == string("acquisitivenesses"));
            CHECK(find(text, "inkonsequentiality") == string("inconsequentially"));
            CHECK(find(text, "iqonsekuentially") == string("inconsequentially"));
            CHECK(find(text, "inkonsekuentiality") == string("inconsekuentiality"));
            CHECK(find(text, "inconsequentiality") == string("inconsekuentiality"));



}


ackuisitivenesses
TEST_CASE("Test replacement of s and z") {
    string text = " saw undemonstrativenesses interchangeablenesses straightforwardnesses representation s  administrators straightforwardness diastereoisomerisms counterculturalisms ";
            CHECK(find(text, "undemonstrativenesses") == string("undemonstrativenesses"));
            CHECK(find(text, "straightforwardnesses") == string("straightforwardnesses"));
            CHECK(find(text, "ztraightforwardnesses") == string("straightforwardnesses"));
            CHECK(find(text, "Ztraightforwardnesses") == string("ztraightforwardnesses"));
            CHECK(find(text, "representation") == string("representation"));
            CHECK(find(text, "repreZentation") == string("representation"));
            CHECK(find(text, "z") == string("s"));
            CHECK(find(text, "administratorZ") == string("administrators"));
            CHECK(find(text, "administrators") == string("adminiZtrators"));
            CHECK(find(text, "saw") == string("saw"));
            CHECK(find(text, "Zaw") == string("saw"));
}



TEST_CASE("Test replacement of d and t") {
    string text = "disadvantageousnesses straightforwardness microradiographies clearheadednesses compendiousnesses dissatisfactions confidentiality administrations advertisements   ";
            CHECK(find(text, "disaTvantageousnesses") == string("disadvantageousnesses"));
            CHECK(find(text, "disadvantageousnesses") == string("disadvantageousnesses"));
            CHECK(find(text, "diTaTvantageousnesses") == string("disadvantageousnesses"));
            CHECK(find(text, "clearheadednesses") == string("clearheadednesses"));
            CHECK(find(text, "clearheaTednesses") == string("clearheadednesses"));
            CHECK(find(text, "clearheaTeTnesses") == string("clearheadednesses"));
            CHECK(find(text, "microraTiographies") == string("microradiographies"));
            CHECK(find(text, "microraDiographies") == string("microradiographies"));
            CHECK(find(text, "microradiographies") == string("microradiographies"));
            CHECK(find(text, "compenTiousnesses") == string("compendiousnesses"));
            CHECK(find(text, "compenTiousnesses") == string("compendiousnesses"));
            CHECK(find(text, "compendiousnesses") == string("compendiousnesses"));
}


TEST_CASE("Test replacement of o and u") {
    string text = "contemporaneousnesses disadvantageousnesses inconsequentialities  lymphogranulomatoses uncommunicativeness undemonstrativeness  sociolinguistically  bloodguiltinesses  ";
            CHECK(find(text, "contemporaneousnesses") == string("contemporaneousnesses"));
            CHECK(find(text, "cUntempUraneUusnesses") == string("contemporaneousnesses"));
            CHECK(find(text, "cuntempUraneUusnesses") == string("contemporaneousnesses"));
            CHECK(find(text, "incUnsequentialities") == string("inconsequentialities"));
            CHECK(find(text, "incOnsequentialities") == string("inconsequentialities"));
            CHECK(find(text, "inconsequentialities") == string("inconsequentialities"));
            CHECK(find(text, "lymphUgranulomatoses") == string("lymphUgranulomatoses"));
            CHECK(find(text, "lymphogranulUmatoses") == string("lymphogranulomatoses"));
            CHECK(find(text, "lymphogranulUmatUses") == string("lymphogranulomatoses"));
            CHECK(find(text, "lymphogranulomatoses") == string("lymphogranulomatoses"));
            CHECK(find(text, "Oncommunicativeness") == string("uncommunicativeness"));
            CHECK(find(text, "UncUmmunicativeness") == string("uncommunicativeness"));
}



TEST_CASE("Test replacement of i and Y") {
    string text = "antiferromagnetically electromyographically photolithographically lymphogranulomatoses cinematographically  conceptualistically  chromatographically    ";
            CHECK(find(text, "antIferromagnetYcally") == string("antiferromagnetically"));
            CHECK(find(text, "antYferromagnetically") == string("antiferromagnetically"));
            CHECK(find(text, "antiferromagnetically") == string("antiferromagnetically"));
            CHECK(find(text, "photolithographically") == string("photolithographically"));
            CHECK(find(text, "photolYthographically") == string("photolithographically"));
            CHECK(find(text, "photolithographYcally") == string("photolithographically"));
            CHECK(find(text, "photolithographYcally") == string("photolithographically"));
            CHECK(find(text, "cYnematographically") == string("cinematographically"));
            CHECK(find(text, "cInematographically") == string("cinematographically"));
            CHECK(find(text, "cinematographicallI") == string("cinematographically"));
            CHECK(find(text, "cYnematographicallI") == string("cinematographically"));
            CHECK(find(text, "antiferromagnetically") == string("antiferromagneticallI"));
}







