#include "../../openpoke.h"
const aBerry Berries[] =
{
	{
		"Cheri", bfSoft, 20, 3,2,
		"Blooms with delicate pretty flowers.",
		"The bright red berry is very spicy.",
		3, 10,0,0,0,0, 25
	},
	{
		"Chesto", bfSuperHard, 80, 3,2,
		"The berry's thick skin and fruit are",
		"very tough. It is dry-tasting all over.",
		3, 0,10,0,0,0, 25
	},
	{
		"Pecha", bfVerySoft, 40, 3,2,
		"Very sweet and delicious.",
		"Also very tender - handle with care.",
		3, 0,0,10,0,0, 25
	},
	{
		"Rawst", bfHard, 32, 3,2,
		"If the leaves grow long and curly,",
		"the berry seems to grow very bitter.",
		3, 0,0,0,10,0, 25
	},
	{
		"Aspear", bfSuperHard, 50, 3,2,
		"The hard berry is dense with a rich",
		"juice. It is quite sour.",
		3, 0,0,0,0,10, 25
	},
	{
		"Leppa", bfVeryHard, 28, 3,2,
		"Grows slower than Cheri and others.",
		"The smaller the berry, the tastier.",
		4, 10,0,10,10,10, 20
	},
	{
		"Oran", bfSuperHard, 35, 3,2,
		"A peculiar berry with a mix of flavors.",
		"Berries grow in half a day.",
		3, 10,10,10,10,10, 20
	},
	{
		"Persim", bfHard, 47, 3,2,
		"Loves sunlight. The berry's color",
		"grows vivid when exposed to the sun.",
		3, 10,10,10,10,10, 20
	},
	{
		"Lum", bfSuperHard, 34, 2,1,
		"Slow to grow. If raised with loving",
		"care, it may grow two berries.",
		12, 10,10,10,10,10, 20
	},
	{
		"Sitrus", bfVeryHard, 95, 3,2,
		"Closely related to Oran. The large",
		"Berry has a well-rounded flavor.",
		6, 10,10,10,10,10, 20
	},
	{
		"Figy", bfSoft, 100, 3,2,
		"The berry, which looks chewed up,",
		"brims with spicy substances.",
		6, 10,0,0,0,0, 25
	},
	{
		"Wiki", bfHard, 115, 3,2,
		"The berry is said to have grown lumpy",
		"to help "POKEMON" grip it.",
		6, 0,10,0,0,0, 25
	},
	{
		"Mago", bfHard, 126, 3,2,
		"The berry turns curvy as it grows.",
		"The curvier, the sweeter and tastier.",
		6, 0,0,10,0,0, 25
	},
	{
		"Aguav", bfSuperHard, 64, 3,2,
		"The flower is dainty. It is rare in its",
		"ability to grow without light.",
		6, 0,0,0,10,0, 25
	},
	{
		"Iapapa", bfSoft, 223, 3,2,
		"The berry is very big and sour.",
		"It takes at least a day to grow.",
		6, 0,0,0,0,10, 25
	},
	{
		"Razz", bfVeryHard, 120, 6,3,
		"The red berry tastes slightly spicy.",
		"It grows quickly in just four hours.",
		1, 10,10,0,0,0, 20
	},
	{
		"Bluk", bfSoft, 108, 6,3,
		"The berry is blue on the outside, but",
		"it blackens the mouth when eaten.",
		1, 0,10,10,0,0, 20
	},
	{
		"Nanab", bfVeryHard, 77, 6,3,
		"This berry was the seventh",
		"discovered in the world. It is sweet.",
		1, 0,0,10,10,0, 20
	},
	{
		"Wepear", bfSuperHard, 74, 6,3,
		"The flower is small and white. It has a",
		"delicate balance of bitter and sour.",
		1, 0,0,0,10,10, 20
	},
	{
		"Pinap", bfHard, 80, 6,3,
		"Weak against wind and cold.",
		"The fruit is spicy and the skin, sour.",
		1, 10,0,0,0,10, 20
	},
	{
		"Pomeg", bfVeryHard, 135, 6,2,
		"However much it is watered,",
		"it only grows up to six berries.",
		3, 10,0,10,10,0, 20
	},
	{
		"Kelpsy", bfHard, 150, 6,2,
		"A rare variety shaped like a root.",
		"Grows a very large flower.",
		3, 0,10,0,10,10, 20
	},
	{
		"Qualot", bfHard, 110, 6,2,
		"Loves water. Grows strong even in",
		"locations with constant rainfall.",
		3, 10,0,10,0,10, 20
	},
	{
		"Hondew", bfHard, 162, 6,2,
		"A berry that is very valuable and",
		"rarely seen. It is very delicious.",
		3, 10,10,0,10,0, 20
	},
	{
		"Grepa", bfSoft, 149, 6,2,
		"Despite its tenderness and round",
		"shape, the berry is unimaginably sour.",
		3, 0,10,10,0,10, 20
	},
	{
		"Tamato", bfSoft, 200, 4,2,
		"The berry is lip-bendingly spicy.",
		"It takes time to grow.",
		6, 20,10,0,0,0, 30
	},
	{
		"Cornn", bfHard, 75, 4,2,
		"A berry from an ancient era. May not",
		"grow unless planted in quantity.",
		6, 0,20,10,0,0, 30
	},
	{
		"Magost", bfHard, 140, 4,2,
		"A berry that is widely said to have",
		"a finely balanced flavor.",
		6, 0,0,20,10,0, 30
	},
	{
		"Rabuta", bfSoft, 226, 4,2,
		"A rare variety that is overgrown with",
		"hair. It is quite bitter.",
		6, 0,0,0,20,10, 30
	},
	{
		"Nomel", bfSuperHard, 29, 4,2,
		"Quite sour. Just one bite makes it",
		"impossible to taste for three days.",
		6, 10,0,0,0,20, 30
	},
	{
		"Spelon", bfSoft, 133, 2,1,
		"The vividly red berry is very spicy.",
		"Its warts secrete a spicy substance.",
		18, 40,10,0,0,0, 70
	},
	{
		"Pamtre", bfVerySoft, 244, 2,1,
		"Drifts on the sea from somewhere.",
		"It is thought to grow elsewhere.",
		18, 0,40,10,0,0, 70
	},
	{
		"Watmel", bfSoft, 250, 2,1,
		"A huge berry, with some over 20",
		"inches discovered. Exceedingly sweet.",
		18, 0,0,40,10,0, 70
	},
	{
		"Durin", bfHard, 24, 2,1,
		"Bitter to even look at. It is so",
		"bitter, no one has ever eaten it as is.",
		18, 0,0,0,40,10, 70
	},
	{
		"Belue", bfVerySoft, 44, 2,1,
		"It is glossy and looks delicious, but",
		"it is awfully sour. Takes time to grow.",
		18, 10,0,0,0,40, 70
	},
	{
		"Liechi", bfVeryHard, 111, 2,1,
		"A mysterious berry. It is rumored to",
		"contain the power of the sea.",
		24, 40,0,40,0,10, 80
	},
	{
		"Ganlon", bfVeryHard, 33, 2,1,
		"A mysterious berry. It is rumored to",
		"contain the power of the land.",
		24, 0,40,0,40,0, 80
	},
	{
		"Salac", bfVeryHard, 95, 2,1,
		"A mysterious berry. It is rumored to",
		"contain the power of the sky.",
		24, 0,0,40,0,40, 80
	},
	{
		"Petaya", bfVeryHard, 237, 2,1,
		"A mysterious berry. It is rumored to",
		"contain the power of all living things.",
		24, 40,0,0,40,0, 80
	},
	{
		"Apicot", bfHard, 75, 2,1,
		"A very mystifying berry. No telling",
		"what may happen or how it can be used.",
		24, 0,40,0,0,40, 80
	},
	{
		"Lansat", bfSoft, 97, 2,1,
		"Said to be a legendary berry.",
		"Holding it supposedly brings joy.",
		24, 10,10,10,10,10, 30
	},
	{
		"Starf", bfSuperHard, 153, 2,1,
		"So strong, it was abandoned at the",
		"world's edge. Considered a mirage.",
		24, 10,10,10,10,10, 30
	},
	{
		"Enigma", 0, 0, 2,1,
		"A completely enigmatic berry.",
		"Appears to have the power of stars.",
		24, 40,40,40,40,40, 40
	},
};
