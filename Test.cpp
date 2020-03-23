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
    string text = "we saw  when grown powder  growing reviewed  somewhere  dishwasher  answerphone . Israel has evidence of the earliest migration of hominids out of Africa.[28] Canaanite tribes are archaeologically attested since the Middle Bronze Age,[29][30] while the Kingdoms of Israel and Judah emerged during the Iron Age.[31][32] The Neo-Assyrian Empire destroyed Israel around 720 BCE.[33] Judah was later conquered by the Babylonian, Persian and Hellenistic empires and had existed as Jewish autonomous provinces.[34][35] The successful Maccabean Revolt led to an independent Hasmonean kingdom by 110 BCE,[36] which in 63 BCE however became a client state of the Roman Republic that subsequently installed the Herodian dynasty in 37 BCE, and in 6 CE created the Roman province of Judea.[37] Judea lasted as a Roman province until the failed Jewish revolts resulted in widespread destruction,[36] the expulsion of the Jewish population[36][38] and the renaming of the region from Iudaea to Syria Palaestina.[39] Jewish presence in the region has persisted to a certain extent over the centuries. In the 7th century CE, the Levant was taken from the Byzantine Empire by the Arabs and";
    CHECK(find(text, "we") == string("ve"));
    CHECK(find(text, "ve") == string("we"));
    CHECK(find(text, "saw") == string("Sav"));
    CHECK(find(text, "when") == string("Vhen"));
}




