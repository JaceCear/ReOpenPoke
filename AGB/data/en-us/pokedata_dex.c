#include "../../openpoke.h"

const aDexEntry DexEntries[] =
{
	{ "Unknown", //#0, ??????????
		0, 0,
		"This is a newly discovered "POKEMON". It is\n"
		"currently under investigation. No detailed\n"
		"information is available at this time.",
		"",
		0, 256, 0, 256
	},
	{ "Seed", //#1, Bulbasaur
		7, 69,
		"There is a plant seed on its back right\n"
		"from the day this "POKEMON" is born.\n"
		"The seed slowly grows larger.",
		"",
		0, 356, 16, 256
	},
	{ "Seed", //#2, Ivysaur
		10, 130,
		"There is a plant bulb on its back.\n"
		"When it absorbs nutrients, the bulb is said\n"
		"to blossom into a large flower.",
		"",
		0, 332, 11, 256
	},
	{ "Seed", //#3, Venusaur
		20, 1000,
		"This "POKEMON" loves the sun, and flowers\n"
		"too. It uses the power of nature to defeat\n"
		"its foes.",
		"",
		0, 256, 1, 375
	},
	{ "Lizard", //#4, Charmander
		6, 85,
		"From the time it is born, a flame burns\n"
		"at the tip of its tail. Its life would end\n"
		"if the flame were to go out.",
		"",
		0, 410, 16, 256
	},
	{ "Flame", //#5, Charmeleon
		11, 190,
		"It lashes about with its tail to knock\n"
		"down its foe. It then tears up the fallen\n"
		"opponent with sharp claws.",
		"",
		0, 294, 8, 256
	},
	{ "Flame", //#6, Charizard
		17, 905,
		"Its wings can carry this "POKEMON" close to\n"
		"an altitude of 1402 meters. It blows out\n"
		"fire at very high temperatures.",
		"",
		0, 271, 0, 317
	},
	{ "Tiny Turtle", //#7, Squirtle
		5, 90,
		"When it retracts its long neck into its\n"
		"shell, it squirts out water with vigorous\n"
		"force.",
		"",
		0, 412, 16, 256
	},
	{ "Turtle", //#8, Wartortle
		10, 225,
		"This "POKEMON" is very popular as a pet.\n"
		"Its fur-covered tail is a symbol of its\n"
		"longevity.",
		"",
		0, 334, 9, 256
	},
	{ "Shellfish", //#9, Blastoise
		16, 855,
		"It crushes its foe under its heavy body\n"
		"to cause fainting. In a pinch, it will\n"
		"withdraw inside its shell.",
		"",
		0, 256, 1, 329
	},
	{ "Worm", //#10, Caterpie
		3, 29,
		"It is covered with a green skin. When it\n"
		"grows, it sheds the skin, covers itself\n"
		"with silk, and becomes a cocoon.",
		"",
		0, 549, 20, 256
	},
	{ "Cocoon", //#11, Metapod
		7, 99,
		"Even though it is encased in a sturdy\n"
		"shell, the body inside is tender.\n"
		"It can't withstand a harsh attack.",
		"",
		0, 350, 18, 256
	},
	{ "Butterfly", //#12, Butterfree
		11, 320,
		"The wings are protected by rain-repellent\n"
		"dust. As a result, this "POKEMON" can fly\n"
		"about even in rain.",
		"",
		0, 312, 2, 256
	},
	{ "Hairy Bug", //#13, Weedle
		3, 32,
		"Often found in forests and grasslands.\n"
		"It has a sharp, toxic barb of around two\n"
		"inches on top of its head.",
		"",
		0, 455, 19, 256
	},
	{ "Cocoon", //#14, Kakuna
		6, 100,
		"This "POKEMON" is still forming its\n"
		"body and cannot move until it is done.",
		"",
		0, 424, 14, 256
	},
	{ "Poison Bee", //#15, Beedrill
		10, 295,
		"May appear in a swarm. Flies at violent\n"
		"speeds, all the while stabbing with the\n"
		"toxic stinger on its rear.",
		"",
		0, 366, 2, 256
	},
	{ "Tiny Bird", //#16, Pidgey
		3, 18,
		"Does not like to fight. It hides in\n"
		"tall grass and so on, foraging for food\n"
		"such as small bugs.",
		"",
		0, 492, 18, 256
	},
	{ "Bird", //#17, Pidgeotto
		11, 300,
		"The claws on its feet are well developed.\n"
		"It can carry prey such as an Exeggcute\n"
		"to its nest over 96 kilometers away.",
		"",
		0, 334, 11, 256
	},
	{ "Bird", //#18, Pidgeot
		15, 395,
		"Can break through the sonic barrier within\n"
		"5 seconds, and can break its enemies even\n"
		"faster.",
		"",
		0, 269, -2, 256
	},
	{ "Mouse", //#19, Rattata
		3, 35,
		"Its fangs are long and very sharp.\n"
		"They grow continuously, so it gnaws on\n"
		"hard things to whittle them down.",
		"",
		0, 481, 18, 256
	},
	{ "Mouse", //#20, Raticate
		7, 185,
		"Its rear feet have three toes each.\n"
		"They are webbed, enabling it to swim\n"
		"across rivers.",
		"",
		0, 401, 14, 256
	},
	{ "Tiny Bird", //#21, Spearow
		3, 20,
		"It busily flits around here and there.\n"
		"Even if it is frail, it can be a tough\n"
		"foe that uses Mirror Move.",
		"",
		0, 571, 19, 256
	},
	{ "Beak", //#22, Fearow
		12, 380,
		"Its huge and magnificent wings can keep it\n"
		"aloft in the sky. It can remain flying a\n"
		"whole day without landing.",
		"",
		0, 282, -1, 272
	},
	{ "Snake", //#23, Ekans
		20, 69,
		"A very common sight in grassland, etc.\n"
		"It flicks its tongue in and out to sense\n"
		"danger in its surroundings.",
		"",
		0, 298, 13, 256
	},
	{ "Cobra", //#24, Arbok
		35, 650,
		"The pattern on its belly appears to be a\n"
		"frightening face. Weak foes will flee just\n"
		"at the sight of the pattern.",
		"",
		0, 256, 0, 296
	},
	{ "Mouse", //#25, Pikachu
		4, 60,
		"Its electrifying charisma makes this the\n"
		"most popular "POKEMON" ever.",
		"It makes it to the front cover of nearly\n"
		"every "POKEMON" related magazine.",
		0, 479, 16, 256
	},
	{ "Mouse", //#26, Raichu
		8, 300,
		"Its electric charges can reach even\n"
		"100,000 volts. Careless contact can cause\n"
		"even an Indian elephant to faint.",
		"",
		0, 426, 10, 256
	},
	{ "Mouse", //#27, Sandshrew
		6, 120,
		"It burrows and lives underground.\n"
		"If threatened, it curls itself up into a\n"
		"ball for protection.",
		"",
		0, 370, 15, 256
	},
	{ "Mouse", //#28, Sandslash
		10, 295,
		"It is adept at attacking with the spines\n"
		"on its back and its sharp claws while\n"
		"quickly scurrying about.",
		"",
		0, 341, 10, 256
	},
	{ "Poison Pin", //#29, Nidoran F
		4, 70,
		"Though small, it must be treated with\n"
		"caution because of its powerfully toxic\n"
		"barbs. The female has smaller horns.",
		"",
		0, 488, 19, 256
	},
	{ "Poison Pin", //#30, Nidorina
		8, 200,
		"The female has a gentle temperament.\n"
		"It emits ultrasonic cries that have the\n"
		"power to befuddle foes.",
		"",
		0, 381, 13, 256
	},
	{ "Drill", //#31, Nidoqueen
		13, 600,
		"The body is covered by stiff, needle-\n"
		"like scales. If it becomes excited,\n"
		"the needles bristle outwards.",
		"",
		0, 283, 2, 256
	},
	{ "Poison Pin", //#32, Nidoran M
		5, 90,
		"Its large ears are flapped like wings\n"
		"when it is listening to distant sounds.\n"
		"It extends toxic barbs when angered.",
		"",
		0, 480, 17, 256
	},
	{ "Poison Pin", //#33, Nidorino
		9, 195,
		"It is easily angered. By swinging its well-\n"
		"developed horn wildly, it can even punch\n"
		"through diamond.",
		"",
		0, 408, 13, 256
	},
	{ "Drill", //#34, Nidoking
		14, 620,
		"It is recognized by its rock-hard hide\n"
		"and its extended horn. Be careful with\n"
		"the horn as it contains venom.",
		"",
		0, 304, 3, 323
	},
	{ "Fairy", //#35, Clefairy
		6, 75,
		"Its adorable appearance makes it popular\n"
		"as a pet. However, it is rare and\n"
		"difficult to find.",
		"",
		0, 425, 18, 256
	},
	{ "Fairy", //#36, Clefable
		13, 400,
		"It has an acute sense of hearing. It can\n"
		"easily hear a pin being dropped nearly\n"
		"a kilometer away.",
		"",
		0, 256, 3, 272
	},
	{ "Fox", //#37, Vulpix
		6, 99,
		"While young, it has six gorgeous tails.\n"
		"When it grows, several new tails are\n"
		"sprouted.",
		"",
		0, 497, 18, 256
	},
	{ "Fox", //#38, Ninetales
		11, 199,
		"It has nine long tails and fur that \n"
		"gleams gold. It is said to live for \n"
		"1,000 years.",
		"",
		0, 339, 6, 256
	},
	{ "Balloon", //#39, Jigglypuff
		5, 55,
		"Scientists recently discovered this\n"
		" can be a great help in insomnia\n"
		"treatment.",
		"",
		0, 419, 19, 256
	},
	{ "Balloon", //#40, Wigglytuff
		10, 120,
		"Its fur is extremely fine, dense, and\n"
		"supple. The exquisitely pleasant fur\n"
		"conveys an image of luxury.",
		"",
		0, 328, 9, 256
	},
	{ "Bat", //#41, Zubat
		8, 75,
		"It has no eyes. Instead, it relies on\n"
		"its ultrasonic cries for echo location to\n"
		"flit about in darkness.",
		"",
		0, 355, -4, 256
	},
	{ "Bat", //#42, Golbat
		16, 550,
		"It clamps down on its prey with needle-\n"
		"sharp fangs and drains over 20 tablespoons\n"
		"of blood in one gulp.",
		"",
		0, 291, 0, 296
	},
	{ "Weed", //#43, Oddish
		5, 54,
		"Its scientific name is “Oddium Wanderus.”\n"
		"At night, it is said to walk nearly 300\n"
		"meters on its two roots.",
		"",
		0, 423, 15, 256
	},
	{ "Weed", //#44, Gloom
		8, 86,
		"Its pistils exude an incredibly foul odor.\n"
		"The horrid stench can cause fainting at a\n"
		"distance of two kilometers.",
		"",
		0, 329, 10, 256
	},
	{ "Flower", //#45, Vileplume
		12, 186,
		"Its petals are the largest in the world.\n"
		"It fiendishly scatters allergy-causing\n"
		"pollen from its petals.",
		"",
		0, 256, 4, 272
	},
	{ "Mushroom", //#46, Paras
		3, 54,
		"Growing out of the bug's back are\n"
		"mushrooms called tochukaso. The mushrooms\n"
		"grow with the bug host.",
		"",
		0, 546, 21, 256
	},
	{ "Mushroom", //#47, Parasect
		10, 295,
		"It scatters toxic spores from the\n"
		"mushroom cap. In China, the spores are\n"
		"used as herbal medicine.",
		"",
		0, 307, 8, 256
	},
	{ "Insect", //#48, Venonat
		10, 300,
		"Its eyes act as radar, enabling it to be\n"
		"active in darkness. The eyes can also\n"
		"shoot powerful beams.",
		"",
		0, 360, 14, 256
	},
	{ "Poison Moth", //#49, Venomoth
		15, 125,
		"The wings are covered with dustlike\n"
		"scales. Every time it flaps its wings, it\n"
		"looses highly toxic dust.",
		"",
		0, 256, 3, 293
	},
	{ "Mole", //#50, Diglett
		2, 8,
		"Recent trials show that you can pick\n"
		"this "POKEMON" and its hole up at\n"
		"the same time.",
		"",
		0, 706, 22, 256
	},
	{ "Mole", //#51, Dugtrio
		7, 333,
		"In battle, it digs through the ground and\n"
		"strikes the unsuspecting foe from an\n"
		"unexpected direction.",
		"",
		0, 384, 14, 256
	},
	{ "Scratch Cat", //#52, Meowth
		4, 42,
		"All it does is sleep during the daytime.\n"
		"At night, it patrols its territory with its\n"
		"eyes aglow.",
		"",
		0, 480, 17, 256
	},
	{ "Classy Cat", //#53, Persian
		10, 320,
		"Has a vicious temperament. Beware if it\n"
		"raises its tail straight up. It is a signal\n"
		"that it is about to pounce and bite.",
		"",
		0, 320, 10, 256
	},
	{ "Duck", //#54, Psyduck
		8, 196,
		"Has a constant migraine caused by\n"
		"schizophrenia and a too heavy bill.\n"
		"It can show amazing powers when annoyed.",
		"",
		0, 347, 11, 256
	},
	{ "Duck", //#55, Golduck
		17, 766,
		"The forelegs are webbed, helping to make\n"
		"it an adept swimmer. It can be seen\n"
		"swimming elegantly in lakes, etc.",
		"",
		0, 272, 4, 287
	},
	{ "Pig Monkey", //#56, Mankey
		5, 280,
		"Light and agile on its feet, and ferocious\n"
		"in temperament. When angered, it flies into\n"
		"an uncontrollable frenzy.",
		"",
		0, 388, 16, 256
	},
	{ "Pig Monkey", //#57, Primeape
		10, 320,
		"It is always outrageously furious. If it\n"
		"gives chase, it will tenaciously track the\n"
		"target no matter how far.",
		"",
		0, 326, 8, 256
	},
	{ "Puppy", //#58, Growlithe
		7, 190,
		"Very friendly and faithful to people.\n"
		"It will try to repel enemies by barking\n"
		"and biting.",
		"",
		0, 346, 14, 256
	},
	{ "Legendary", //#59, Arcanine
		19, 1550,
		"A "POKEMON" that is described in Chinese\n"
		"legends. It is said to race at an\n"
		"unbelievable speed.",
		"",
		0, 256, -1, 312
	},
	{ "Tadpole", //#60, Poliwag
		6, 124,
		"Its slick black skin is thin and damp.\n"
		"A part of its internal organs can be seen\n"
		"through the skin as a spiral pattern.",
		"",
		0, 353, 17, 256
	},
	{ "Tadpole", //#61, Poliwhirl
		10, 200,
		"Its two legs are well developed.\n"
		"Even though it can live on the ground,\n"
		"it prefers living in water.",
		"",
		0, 288, 10, 256
	},
	{ "Tadpole", //#62, Poliwrath
		13, 540,
		"An adept swimmer, it knows the front\n"
		"crawl, butterfly, and more. It is faster\n"
		"than the best human swimmers.",
		"",
		0, 256, 5, 256
	},
	{ "Psi", //#63, Abra
		9, 195,
		"It sleeps for 18 hours a day. It uses a\n"
		"variety of extrasensory powers even\n"
		"while asleep.",
		"",
		0, 374, 14, 256
	},
	{ "Psi", //#64, Kadabra
		13, 565,
		"It happened one morning - a boy with\n"
		"extrasensory powers awoke in bed\n"
		"transformed into Kadabra.",
		"",
		0, 272, 2, 256
	},
	{ "Psi", //#65, Alakazam
		15, 480,
		"It does not like physical attacks very \n"
		"much. Instead, it freely uses extra-\n"
		"sensory powers to defeat foes.",
		"",
		0, 272, -1, 271
	},
	{ "Superpower", //#66, Machop
		8, 195,
		"Its whole body is composed of muscles.\n"
		"Even though it's the size of a human\n"
		"child, it can hurl 100 grown-ups.",
		"",
		0, 320, 12, 256
	},
	{ "Superpower", //#67, Machoke
		15, 705,
		"Its formidable body never gets tired.\n"
		"It helps people by doing work such as\n"
		"the moving of heavy goods.",
		"",
		0, 304, 6, 256
	},
	{ "Superpower", //#68, Machamp
		16, 1300,
		"Its four ruggedly developed arms can\n"
		"launch a flurry of 1,000 punches in just\n"
		"two seconds.",
		"",
		0, 278, 2, 283
	},
	{ "Flower", //#69, Bellsprout
		7, 40,
		"Its bud looks like a human face. Because\n"
		"of the bud, it is rumored to be a type of\n"
		"legendary mandrake plant.",
		"",
		0, 354, 16, 256
	},
	{ "Flycatcher", //#70, Weepinbell
		10, 64,
		"The leafy parts act as cutters for\n"
		"slashing foes. It spits a fluid that\n"
		"dissolves everything.",
		"",
		0, 256, -1, 256
	},
	{ "Flycatcher", //#71, Victreebel
		17, 155,
		"Lures prey into its mouth with a honeylike\n"
		"aroma. The helpless prey is melted with\n"
		"a dissolving fluid.",
		"",
		0, 256, 2, 302
	},
	{ "Jellyfish", //#72, Tentacool
		9, 455,
		"Its eyes are as transparent as crystals.\n"
		"From them, it shoots mysterious\n"
		"beams of light.",
		"",
		0, 256, 0, 256
	},
	{ "Jellyfish", //#73, Tentacruel
		16, 550,
		"It has 80 tentacles that move about\n"
		"freely. They can sting, causing poisoning\n"
		"and sharp, stabbing pain.",
		"",
		0, 272, -1, 312
	},
	{ "Rock", //#74, Geodude
		4, 200,
		"Its round form makes it easy to pick up.\n"
		"Some people have used them to hurl\n"
		"at each other in a snowball fight.",
		"",
		0, 330, 17, 256
	},
	{ "Rock", //#75, Graveler
		10, 1050,
		"Be careful while hiking on mountain trails.\n"
		"Graveler may come rolling down the path\n"
		"without slowing.",
		"",
		0, 272, 8, 305
	},
	{ "Megaton", //#76, Golem
		14, 3000,
		"It is enclosed in a hard shell that is as\n"
		"rugged as slabs of rock. It sheds skin\n"
		"once a year to grow larger.",
		"",
		0, 266, 3, 298
	},
	{ "Fire Horse", //#77, Ponyta
		10, 300,
		"Its body is light, and its legs are\n"
		"incredibly powerful. It can clear\n"
		"Ayers Rock in one leap.",
		"",
		0, 288, 7, 256
	},
	{ "Fire Horse", //#78, Rapidash
		17, 950,
		"It can gallop at a top speed of 240\n"
		"km/h. It can race as fast as a\n"
		"bullet train while ablaze.",
		"",
		0, 282, -1, 312
	},
	{ "Dopey", //#79, Slowpoke
		12, 360,
		"Slowpoke is slow. Oh, and it can fish with\n"
		"it's tail too, but it usually just stands\n"
		"there.",
		"",
		0, 271, 10, 272
	},
	{ "Hermit Crab", //#80, Slowbro
		16, 785,
		"Slowbro is not a true "POKEMON" in the fact\n"
		"that if you take the Shellder off, it\n"
		"reverts back to Slowpoke.",
		"",
		0, 257, -2, 312
	},
	{ "Magnet", //#81, Magnemite
		3, 60,
		"It moves while constantly hovering.\n"
		"It discharges Thunder Wave and so on\n"
		"from the units at its sides.",
		"",
		0, 294, -8, 256
	},
	{ "Magnet", //#82, Magneton
		10, 600,
		"A linked cluster formed of several\n"
		"Magnemite. It discharges powerful\n"
		"magnetic waves at high voltage.",
		"",
		0, 293, -4, 273
	},
	{ "Wild Duck", //#83, Farfetch'd
		8, 150,
		"It always walks about with a plant stalk\n"
		"clamped in its beak. The stalk is used for\n"
		"building its nest.",
		"",
		0, 317, -2, 256
	},
	{ "Twin Bird", //#84, Doduo
		14, 392,
		"A two-headed "POKEMON" that was discovered\n"
		"as a sudden mutation. It runs at a pace\n"
		"of over 96 kilometers per hour.",
		"",
		0, 256, 3, 287
	},
	{ "Triple Bird", //#85, Dodrio
		18, 852,
		"An odd species that is rarely found.\n"
		"The three heads respectively represent\n"
		"joy, sadness, and anger.",
		"",
		0, 272, -2, 296
	},
	{ "Sea Lion", //#86, Seel
		11, 900,
		"Covered with light blue fur, its hide is\n"
		"thick and tough. It is active in bitter\n"
		"cold of -40°C.",
		"",
		0, 298, 8, 256
	},
	{ "Sea Lion", //#87, Dewgong
		17, 1200,
		"Its body is covered with a pure white\n"
		"fur. The colder the weather, the more\n"
		"active it becomes.",
		"",
		0, 288, 1, 306
	},
	{ "Sludge", //#88, Grimer
		9, 300,
		"Sludge exposed to X rays from the moon\n"
		"transformed into Grimer. It loves feeding\n"
		"on filthy things.",
		"",
		0, 258, 8, 256
	},
	{ "Sludge", //#89, Muk
		12, 300,
		"Its very poisonous and smells so bad,\n"
		"its' stench penetrates the outside of\n"
		""POKE" Balls.",
		"",
		0, 288, 7, 288
	},
	{ "Bivalve", //#90, Shellder
		3, 40,
		"It is encased in a shell that is harder\n"
		"than diamond. Inside, however, it is\n"
		"surprisingly tender.",
		"",
		0, 643, 21, 256
	},
	{ "Bivalve", //#91, Cloyster
		15, 1325,
		"Its shell is extremely hard. It cannot be\n"
		"shattered, even with a bomb. The shell\n"
		"opens only when it is attacking.",
		"",
		0, 264, 0, 288
	},
	{ "Gas", //#92, Gastly
		13, 1,
		"A being that exists as a thin gas. It can\n"
		"topple an Indian elephant by enveloping\n"
		"the prey in two seconds.",
		"",
		0, 256, 0, 256
	},
	{ "Gas", //#93, Haunter
		16, 1,
		"If you get the feeling of being watched\n"
		"in darkness when nobody is around,\n"
		"Haunter is there.",
		"",
		0, 269, 2, 308
	},
	{ "Shadow", //#94, Gengar
		15, 405,
		"It is said to emerge from darkness to\n"
		"steal the lives of those who become lost\n"
		"in mountains.",
		"",
		0, 256, 4, 317
	},
	{ "Rock Snake", //#95, Onix
		88, 2100,
		"It usually lives underground. It searches\n"
		"for food while boring its way through the\n"
		"ground at 80 kilometers per hour.",
		"",
		0, 257, 0, 515
	},
	{ "Hypnosis", //#96, Drowzee
		10, 324,
		"A descendent of the legendary animal\n"
		"baku, which is said to eat dreams. It is\n"
		"skilled at hypnotism.",
		"",
		0, 274, 7, 256
	},
	{ "Hypnosis", //#97, Hypno
		16, 756,
		"It carries a pendulum-like device. There\n"
		"once was an incident in which it took\n"
		"away a child it hypnotized.",
		"",
		0, 298, 3, 310
	},
	{ "River Crab", //#98, Krabby
		4, 65,
		"It can be found near the sea. The large\n"
		"pincers grow back if they are torn out of\n"
		"their sockets.",
		"",
		0, 469, 18, 256
	},
	{ "Pincer", //#99, Kingler
		13, 600,
		"Its large and hard pincer has 10,000-\n"
		"horsepower strength. However, being so\n"
		"big, it is unwieldy to move.",
		"",
		0, 287, 3, 308
	},
	{ "Ball", //#100, Voltorb
		5, 104,
		"Often mistaken for a "POKE" Ball.\n"
		"But when you touch it, you come to\n"
		"a shocking conclusion.",
		"",
		0, 364, -8, 256
	},
	{ "Ball", //#101, Electrode
		12, 666,
		"It explodes in response to even minor\n"
		"stimuli. It is feared, with the nickname\n"
		"of “The Bomb Ball.”",
		"",
		0, 256, 0, 256
	},
	{ "Egg", //#102, Exeggcute
		4, 25,
		"Even though it appears to be eggs of\n"
		"some sort, it was discovered to be a life-\n"
		"form more like plant seeds.",
		"",
		0, 495, -4, 256
	},
	{ "Coconut", //#103, Exeggutor
		20, 1200,
		"It is called “The Walking Tropical\n"
		"Rainforest.” Each of the nuts has\n"
		"a face and a will of its own.",
		"",
		0, 283, 0, 376
	},
	{ "Lonely", //#104, Cubone
		4, 65,
		"It wears the skull of its dead mother on\n"
		"its head. When it becomes lonesome, it is\n"
		"said to cry loudly.",
		"",
		0, 545, 19, 256
	},
	{ "Bone Keeper", //#105, Marowak
		10, 450,
		"It is small and was originally very weak.\n"
		"Its temperament turned ferocious when it\n"
		"began using bones.",
		"",
		0, 293, 12, 256
	},
	{ "Kicking", //#106, Hitmonlee
		15, 498,
		"The legs freely contract and stretch.\n"
		"The stretchy legs allow it to hit a\n"
		"distant foe with a rising kick.",
		"",
		0, 256, 0, 273
	},
	{ "Punching", //#107, Hitmonchan
		14, 502,
		"The spirit of a pro boxer has infused this\n"
		""POKEMON". It throws punches that are\n"
		"faster than a bullet train.",
		"",
		0, 256, 1, 264
	},
	{ "Licking", //#108, Lickitung
		12, 655,
		"Its tongue is twice the length of its\n"
		"body. It can be moved like an arm for\n"
		"grabbing food and attacking.",
		"",
		0, 272, 3, 272
	},
	{ "Poison Gas", //#109, Koffing
		6, 10,
		"Its thin, balloon-like body is inflated by\n"
		"horribly toxic gases. It reeks when it is\n"
		"nearby.",
		"",
		0, 369, -1, 256
	},
	{ "Poison Gas", //#110, Weezing
		12, 95,
		"Very rarely, a sudden mutation can result\n"
		"in two small Koffing twins becoming\n"
		"conjoined as a Weezing.",
		"",
		0, 321, -1, 276
	},
	{ "Spikes", //#111, Rhyhorn
		10, 1150,
		"Strong, but not too bright, this "POKEMON"\n"
		"can shatter even a skyscraper with its\n"
		"charging Tackles.",
		"",
		0, 291, 7, 276
	},
	{ "Drill", //#112, Rhydon
		19, 1200,
		"It begins walking on its hind legs after\n"
		"evolution. It can punch holes through\n"
		"boulders with its horn.",
		"",
		0, 272, -1, 344
	},
	{ "Egg", //#113, Chansey
		11, 346,
		"It lays several eggs a day. The eggs are\n"
		"apparently rich in nutrients and extremely\n"
		"delicious.",
		"",
		0, 257, 6, 256
	},
	{ "Vine", //#114, Tangela
		10, 350,
		"Blue plant vines cloak the "POKEMON"'s\n"
		"identity in a tangled mass. It entangles\n"
		"anything that gets close.",
		"",
		0, 320, 9, 256
	},
	{ "Parent", //#115, Kangaskhan
		22, 800,
		"The female raises its offspring in a pouch\n"
		"on its belly. It is skilled at attacking\n"
		"using Comet Punch.",
		"",
		0, 257, -3, 349
	},
	{ "Dragon", //#116, Horsea
		4, 80,
		"It maintains balance using its tail, which\n"
		"is wound up like a coil. It may spray ink\n"
		"from its mouth.",
		"",
		0, 399, -1, 256
	},
	{ "Dragon", //#117, Seadra
		12, 250,
		"Its body bristles with sharp spikes.\n"
		"Carelessly trying to touch it could cause\n"
		"fainting from the spikes.",
		"",
		0, 296, 3, 256
	},
	{ "Goldfish", //#118, Goldeen
		6, 150,
		"Its dorsal and pectoral fins are strongly\n"
		"developed like muscles. It can swim at a\n"
		"speed of five knots.",
		"",
		0, 379, 4, 256
	},
	{ "Goldfish", //#119, Seaking
		13, 390,
		"The horn on its head is sharp like a\n"
		"drill. It bores a hole in a boulder to\n"
		"make its nest.",
		"",
		0, 304, 1, 288
	},
	{ "Star Shape", //#120, Staryu
		8, 345,
		"It appears in large numbers by seashores.\n"
		"At night, its central core flashes with a\n"
		"red light.",
		"",
		0, 326, 1, 256
	},
	{ "Mysterious", //#121, Starmie
		11, 800,
		"This "POKEMON" has a geometric body.\n"
		"Because of its body, the locals suspect\n"
		"that it is an alien creature.",
		"",
		0, 301, 3, 256
	},
	{ "Barrier", //#122, Mr. Mime
		13, 545,
		"It is adept at conning people. It is said\n"
		"to be able to create walls out of thin\n"
		"air by miming.",
		"",
		0, 258, 4, 256
	},
	{ "Mantis", //#123, Scyther
		15, 560,
		"It tears and shreds prey with its wickedly\n"
		"sharp scythes. It very rarely spreads its\n"
		"wings to fly.",
		"",
		0, 272, 0, 293
	},
	{ "Human Shape", //#124, Jynx
		14, 406,
		"It speaks using a language that sounds\n"
		"human. Research is under way to determine\n"
		"what is being said.",
		"",
		0, 256, 3, 300
	},
	{ "Electric", //#125, Electabuzz
		11, 300,
		"It loves to feed on strong electricity.\n"
		"It occasionally appears around large\n"
		"power plants and so on.",
		"",
		0, 330, 7, 256
	},
	{ "Spitfire", //#126, Magmar
		13, 445,
		"Found near the mouth of a volcano.\n"
		"This fire-breather's body temperature is\n"
		"nearly 1200°C.",
		"",
		0, 293, 4, 272
	},
	{ "Stag Beetle", //#127, Pinsir
		15, 550,
		"Its two long pincer horns are powerful.\n"
		"Once they grip an enemy, they won't\n"
		"release until the foe is torn.",
		"",
		0, 256, 1, 257
	},
	{ "Wild Bull", //#128, Tauros
		14, 884,
		"When it is about to Tackle, it whips\n"
		"its body repeatedly with its three\n"
		"long tails.",
		"",
		0, 256, 2, 312
	},
	{ "Fish", //#129, Magikarp
		9, 100,
		"It is virtually worthless in terms of both\n"
		"power and speed. It is the most weak and\n"
		"pathetic "POKEMON" in the world.",
		"",
		0, 317, 4, 256
	},
	{ "Atrocious", //#130, Gyarados
		65, 2350,
		"It has an extremely aggressive nature.\n"
		"The Hyper Beam it shoots from its mouth\n"
		"totally incinerates all targets.",
		"",
		0, 288, -1, 512
	},
	{ "Transport", //#131, Lapras
		25, 2200,
		"Its high intelligence enables it to\n"
		"understand human speech. It likes to ferry\n"
		"people on its back.",
		"",
		0, 256, 0, 425
	},
	{ "Transform", //#132, Ditto
		3, 40,
		"By looking into the soul of another "POKEMON",\n"
		"it can copy that "POKEMON"'s form.",
		"",
		0, 602, 21, 256
	},
	{ "Evolution", //#133, Eevee
		3, 65,
		"An extremely rare "POKEMON" that may\n"
		"evolve in a number of different ways\n"
		"depending on stimuli.",
		"",
		0, 476, 17, 256
	},
	{ "Bubble Jet", //#134, Vaporeon
		10, 290,
		"Its body's cellular structure is similar to\n"
		"the molecular composition of water.\n"
		"It can melt invisibly in water.",
		"",
		0, 316, 7, 256
	},
	{ "Lightning", //#135, Jolteon
		8, 245,
		"If it is angered or startled, the fur all\n"
		"over its body bristles like sharp needles\n"
		"that pierce foes.",
		"",
		0, 283, 8, 256
	},
	{ "Flame", //#136, Flareon
		9, 250,
		"It has a flame bag inside its body. After\n"
		"inhaling deeply, it blows out flames of\n"
		"nearly 1700°C.",
		"",
		0, 302, 11, 256
	},
	{ "Virtual", //#137, Porygon
		8, 365,
		"It is unknown if this was programmed in\n"
		"C, C++ or C#. It definately wasn't Java,\n"
		"though…",
		"",
		0, 328, 7, 256
	},
	{ "Spiral", //#138, Omanyte
		4, 75,
		"A prehistoric "POKEMON" that lived in the\n"
		"primordial sea, it swims by twisting its\n"
		"10 tentacles about.",
		"",
		0, 521, 20, 256
	},
	{ "Spiral", //#139, Omastar
		10, 350,
		"Its tentacles are highly developed as if\n"
		"they are hands and feet. As soon as it\n"
		"ensnares prey, it bites.",
		"",
		0, 307, 5, 256
	},
	{ "Shellfish", //#140, Kabuto
		5, 115,
		"This "POKEMON" was regenerated from the\n"
		"fossil of an ancient creature. It protects\n"
		"itself with a hard shell.",
		"",
		0, 438, 21, 256
	},
	{ "Shellfish", //#141, Kabutops
		13, 405,
		"It swims freely through water. It catches\n"
		"prey with its scythe-like arms and drains\n"
		"the victim's fluids.",
		"",
		0, 271, 1, 256
	},
	{ "Fossil", //#142, Aerodactyl
		18, 590,
		"It was regenerated from a dinosaur's\n"
		"genetic matter that was found in amber.\n"
		"It flies with high-pitched cries.",
		"",
		0, 275, -1, 317
	},
	{ "Sleeping", //#143, Snorlax
		21, 4600,
		"It is not satisfied unless it eats over 880\n"
		"pounds of food every day. When it is done\n"
		"eating, it goes promptly to sleep.",
		"",
		0, 275, 1, 408
	},
	{ "Freeze", //#144, Articuno
		17, 554,
		"One of the legendary bird "POKEMON".\n"
		"With its long tail trailing behind, its\n"
		"flying form is magnificent.",
		"",
		0, 278, 0, 308
	},
	{ "Electric", //#145, Zapdos
		16, 526,
		"One of the legendary bird "POKEMON".\n"
		"While it is flying, it makes crackling and\n"
		"snapping sounds.",
		"",
		0, 275, 1, 330
	},
	{ "Flame", //#146, Moltres
		20, 600,
		"One of the legendary bird "POKEMON".\n"
		"Those seeing it are overwhelmed by its\n"
		"orange wings that seem to be on fire.",
		"",
		0, 270, 1, 379
	},
	{ "Dragon", //#147, Dratini
		18, 33,
		"Even the young can exceed 2 meters in\n"
		"length. It grows larger by repeatedly\n"
		"shedding skin.",
		"",
		0, 256, 8, 386
	},
	{ "Dragon", //#148, Dragonair
		40, 165,
		"It is said to live in seas and lakes.\n"
		"Even though it has no wings, it has been\n"
		"seen flying occasionally.",
		"",
		0, 274, 0, 423
	},
	{ "Dragon", //#149, Dragonite
		22, 2100,
		"It can fly in spite of its big and bulky\n"
		"physique. It circles the globe in just\n"
		"16 hours.",
		"",
		0, 283, -1, 342
	},
	{ "Genetic", //#150, Mewtwo
		20, 1220,
		"A clone of the mysterious Mew. It cannot\n"
		"control its own power.",
		"",
		0, 276, -1, 342
	},
	{ "New Species", //#151, Mew
		4, 40,
		"Its incredible learning skills make it\n"
		"able to learn any skill.",
		"While it was thought to be extinct, it\n"
		"actually made the ancient Missingnos\n"
		"extinct.",
		0, 460, -2, 256
	},
	{ "Leaf", //#152, Chikorita
		9, 64,
		"Its pleasantly aromatic leaves have the\n"
		"ability to check the humidity and\n"
		"temperature.",
		"",
		0, 512, 18, 256
	},
	{ "Leaf", //#153, Bayleef
		12, 158,
		"A spicy aroma emanates from around its\n"
		"neck. The aroma acts as a stimulant to\n"
		"restore health.",
		"",
		0, 296, 4, 256
	},
	{ "Herb", //#154, Meganium
		18, 1005,
		"Meganium's breath has the power to revive\n"
		"dead grass and plants. It can make them\n"
		"healthy again.",
		"",
		0, 286, 0, 317
	},
	{ "Fire Mouse", //#155, Cyndaquil
		5, 79,
		"It usually stays hunched over. If it is\n"
		"angry or surprised, it shoots flames out\n"
		"of its back.",
		"",
		0, 539, 19, 256
	},
	{ "Volcano", //#156, Quilava
		9, 190,
		"This "POKEMON" is fully covered by\n"
		"nonflammable fur. It can withstand any\n"
		"kind of fire attack.",
		"",
		0, 329, 10, 256
	},
	{ "Volcano", //#157, Typhlosion
		17, 795,
		"It has a secret, devastating move. It\n"
		"rubs its blazing fur together to cause\n"
		"huge explosions.",
		"",
		0, 284, -1, 287
	},
	{ "Big Jaw", //#158, Totodile
		6, 95,
		"It is small but rough and tough. It won't\n"
		"hesitate to take a bite out of anything\n"
		"that moves.",
		"",
		0, 487, 20, 256
	},
	{ "Big Jaw", //#159, Croconaw
		11, 250,
		"It opens its huge jaws wide when\n"
		"attacking. If it loses any fangs while\n"
		"biting, they grow back in.",
		"",
		0, 378, 11, 256
	},
	{ "Big Jaw", //#160, Feraligatr
		23, 888,
		"It is hard for it to support its own\n"
		"weight out of water, so it gets down on\n"
		"all fours. But it moves fast.",
		"",
		0, 282, -1, 375
	},
	{ "Scout", //#161, Sentret
		8, 60,
		"It stands on its tail so it can see a long\n"
		"way. If it spots an enemy, it cries loudly\n"
		"to warn its kind.",
		"",
		0, 439, 12, 256
	},
	{ "Long Body", //#162, Furret
		18, 325,
		"There is no telling where its tail begins.\n"
		"Despite its short legs, it is quick at\n"
		"hunting Rattata.",
		"",
		0, 346, 10, 256
	},
	{ "Owl", //#163, Hoothoot
		7, 212,
		"It has a perfect sense of time. Whatever\n"
		"happens, it keeps rhythm by precisely\n"
		"tilting its head in time.",
		"",
		0, 380, 15, 256
	},
	{ "Owl", //#164, Noctowl
		16, 408,
		"When it needs to think, it rotates its head\n"
		"180° to sharpen its intellectual power.",
		"",
		0, 278, 2, 256
	},
	{ "Five Star", //#165, Ledyba
		10, 108,
		"When the weather turns cold, numerous\n"
		"Ledyba gather from everywhere to cluster\n"
		"and keep each other warm.",
		"",
		0, 256, 4, 256
	},
	{ "Five Star", //#166, Ledian
		14, 356,
		"The star patterns on its back grow larger\n"
		"or smaller depending on the number of\n"
		"stars in the night sky.",
		"",
		0, 256, 1, 256
	},
	{ "String Spit", //#167, Spinarak
		5, 85,
		"It spins a web using fine--but durable--\n"
		"thread. It then waits patiently for prey\n"
		"to be trapped.",
		"",
		0, 414, 20, 256
	},
	{ "Long Leg", //#168, Ariados
		11, 335,
		"A single strand of a special string is\n"
		"endlessly spun out of its rear. The string\n"
		"leads back to its nest.",
		"",
		0, 316, 7, 256
	},
	{ "Bat", //#169, Crobat
		18, 750,
		"The development of wings on its legs\n"
		"enables it to fly fast but also makes it\n"
		"tough to stop and rest.",
		"",
		0, 279, -1, 313
	},
	{ "Angler", //#170, Chinchou
		5, 120,
		"On the dark ocean floor, its only means\n"
		"of communication is its constantly\n"
		"flashing lights.",
		"",
		0, 424, -2, 256
	},
	{ "Light", //#171, Lanturn
		12, 225,
		"It blinds prey with an intense burst of\n"
		"light, then swallows the immobilized prey\n"
		"in a single gulp.",
		"",
		0, 269, 6, 256
	},
	{ "Tiny Mouse", //#172, Pichu
		3, 20,
		"Despite its small size, it can zap even\n"
		"adult humans. However, if it does so, it\n"
		"also surprises itself.",
		"",
		0, 508, 17, 256
	},
	{ "Star Shape", //#173, Cleffa
		3, 30,
		"When numerous meteors illuminate the\n"
		"night sky, sightings of CLEFFA strangely\n"
		"increase.",
		"",
		0, 462, 22, 256
	},
	{ "Balloon", //#174, Igglybuff
		3, 10,
		"Its extremely flexible and elastic body\n"
		"makes it bounce continuously--anytime,\n"
		"anywhere.",
		"",
		0, 457, -1, 256
	},
	{ "Spike Ball", //#175, Togepi
		3, 15,
		"A proverb claims that happiness will come\n"
		"to anyone who can make a sleeping TOGEPI\n"
		"stand up.",
		"",
		0, 507, 21, 256
	},
	{ "Happiness", //#176, Togetic
		6, 32,
		"It grows dispirited if it is not with kind\n"
		"people. It can float in midair without\n"
		"moving its wings.",
		"",
		0, 424, 15, 256
	},
	{ "Tiny Bird", //#177, Natu
		2, 20,
		"It usually forages for food on the ground\n"
		"but may, on rare occasions, hop onto\n"
		"branches to peck at shoots.",
		"",
		0, 610, 23, 256
	},
	{ "Mystic", //#178, Xatu
		15, 150,
		"In South America, it is said that its right\n"
		"eye sees the future and its left eye\n"
		"views the past.",
		"",
		0, 258, 4, 317
	},
	{ "Wool", //#179, Mareep
		6, 78,
		"Warm and soft due to its fast growing fleece.\n"
		"Known to cause sleepiness when in large\n"
		"numbers.",
		"",
		0, 379, 18, 256
	},
	{ "Wool", //#180, Flaaffy
		8, 133,
		"Its fluffy fleece easily stores\n"
		"electricity. Its rubbery hide keeps it\n"
		"from being electrocuted.",
		"",
		0, 372, 13, 256
	},
	{ "Light", //#181, Ampharos
		14, 615,
		"The bright light on its tail can be seen\n"
		"far away. It has been treasured since\n"
		"ancient times as a beacon.",
		"",
		0, 275, 2, 283
	},
	{ "Flower", //#182, Bellossom
		4, 58,
		"Plentiful in the tropics. When it dances,\n"
		"its petals rub together and make a\n"
		"pleasant ringing sound.",
		"",
		0, 472, 19, 256
	},
	{ "Aqua Mouse", //#183, Marill
		4, 85,
		"The end of its tail serves as a buoy that\n"
		"keeps it from drowning, even in a vicious\n"
		"current.",
		"",
		0, 476, 19, 256
	},
	{ "Aqua Rabbit", //#184, Azumarill
		8, 285,
		"When it plays in water, it rolls up its\n"
		"elongated ears to prevent their insides\n"
		"from getting wet.",
		"",
		0, 448, 15, 256
	},
	{ "Imitation", //#185, Sudowoodo
		12, 380,
		"It disguises itself as a tree to avoid\n"
		"attack. It hates water, so it will\n"
		"disappear if it starts raining.",
		"",
		0, 305, 7, 256
	},
	{ "Frog", //#186, Politoed
		11, 339,
		"Whenever three or more of these get\n"
		"together, they sing in a loud voice that\n"
		"sounds like bellowing.",
		"",
		0, 289, 5, 256
	},
	{ "Cottonweed", //#187, Hoppip
		4, 5,
		"Its body is so light, it must grip the\n"
		"ground firmly with its feet to keep from\n"
		"being blown away.",
		"",
		0, 562, -7, 256
	},
	{ "Cottonweed", //#188, Skiploom
		6, 10,
		"It spreads its petals to absorb sunlight.\n"
		"It also floats in the air to get closer to\n"
		"the sun.",
		"",
		0, 387, 0, 256
	},
	{ "Cottonweed", //#189, Jumpluff
		8, 30,
		"It drifts on seasonal winds and spreads\n"
		"its cotton-like spores all over the world \n"
		"to make more offspring.",
		"",
		0, 418, -4, 256
	},
	{ "Long Tail", //#190, Aipom
		8, 115,
		"It lives atop tall trees. When leaping\n"
		"from branch to branch, it deftly uses its\n"
		"tail for balance.",
		"",
		0, 363, 8, 256
	},
	{ "Seed", //#191, Sunkern
		3, 18,
		"It lives by drinking only dewdrops from\n"
		"under the leaves of plants. It is said\n"
		"that it eats nothing else.",
		"",
		0, 541, 0, 256
	},
	{ "Sun", //#192, Sunflora
		8, 85,
		"In the daytime, it rushes about in a\n"
		"hectic manner, but it comes to a complete\n"
		"stop when the sun sets.",
		"",
		0, 374, 12, 256
	},
	{ "Clear Wing", //#193, Yanma
		12, 380,
		"Its large eyes can scan 360°.\n"
		"It looks in all directions to seek out\n"
		"insects as its prey.",
		"",
		0, 274, -4, 256
	},
	{ "Water Fish", //#194, Wooper
		4, 85,
		"When it walks around on the ground,\n"
		"it coats its body with a slimy, poisonous\n"
		"film.",
		"",
		0, 479, 20, 256
	},
	{ "Water Fish", //#195, Quagsire
		14, 750,
		"Due to its relaxed and carefree attitude,\n"
		"it often bumps its head on boulders and\n"
		"boat hulls as it swims.",
		"",
		0, 273, 4, 273
	},
	{ "Sun", //#196, Espeon
		9, 265,
		"By reading air currents, it can predict\n"
		"things such as the weather or its foe's\n"
		"next move.",
		"",
		0, 363, 12, 256
	},
	{ "Moonlight", //#197, Umbreon
		10, 270,
		"When darkness falls, the rings on its body\n"
		"begin to glow, striking fear in the hearts\n"
		"of anyone nearby.",
		"",
		0, 317, 9, 256
	},
	{ "Darkness", //#198, Murkrow
		5, 21,
		"It is said that when chased, it lures its\n"
		"attacker onto dark mountain trails where\n"
		"the foe will get lost.",
		"",
		0, 401, -8, 256
	},
	{ "Royal", //#199, Slowking
		20, 795,
		"When its head was bitten, toxins entered\n"
		"Slowpoke's head and unlocked an\n"
		"extraordinary power.",
		"",
		0, 265, -1, 330
	},
	{ "Screech", //#200, Misdreavus
		7, 10,
		"It loves to bite and yank people's hair\n"
		"from behind without warning, just to see\n"
		"their shocked reactions.",
		"",
		0, 407, -8, 256
	},
	{ "Symbol", //#201, Unown
		5, 50,
		"There are as many as 28 known variations\n"
		"of this "POKEMON". More may be discovered in\n"
		"the future.",
		"",
		0, 411, 2, 256
	},
	{ "Patient", //#202, Wobbuffet
		13, 285,
		"To keep its pitch-black tail hidden, it\n"
		"lives quietly in the darkness. It is never\n"
		"first to attack.",
		"",
		0, 274, 4, 256
	},
	{ "Long Neck", //#203, Girafarig
		15, 415,
		"Its tail, which also contains a small\n"
		"brain, may bite on its own if it notices an\n"
		"alluring smell.",
		"",
		0, 281, 2, 256
	},
	{ "Bagworm", //#204, Pineco
		6, 72,
		"It hangs and waits for flying-insect prey\n"
		"to come near. It does not move about\n"
		"much on its own.",
		"",
		0, 445, 2, 256
	},
	{ "Bagworm", //#205, Forretress
		12, 1258,
		"It remains immovably rooted to its tree.\n"
		"It scatters pieces of its hard shell to\n"
		"drive its enemies away.",
		"",
		0, 293, 5, 256
	},
	{ "Land Snake", //#206, Dunsparce
		15, 140,
		"If spotted, it escapes by burrowing with\n"
		"its tail. It can hover just slightly using\n"
		"its wings.",
		"",
		0, 284, 15, 256
	},
	{ "Flyscorpion", //#207, Gligar
		11, 648,
		"It usually clings to cliffs. When it spots\n"
		"its prey, it spreads its wings and glides\n"
		"down to attack.",
		"",
		0, 350, -1, 256
	},
	{ "Iron Snake", //#208, Steelix
		92, 4000,
		"It is said that if an Onix lives for over\n"
		"100 years, its composition changes to\n"
		"become diamond-like.",
		"",
		0, 278, -1, 557
	},
	{ "Fairy", //#209, Snubbull
		6, 78,
		"It has an active, playful nature. Many\n"
		"women like to frolic with it because of\n"
		"its affectionate ways.",
		"",
		0, 465, 18, 256
	},
	{ "Fairy", //#210, Granbull
		14, 487,
		"Because its fangs are too heavy, it\n"
		"always keeps its head tilted down.\n"
		"However, its Bite is powerful.",
		"",
		0, 256, 3, 256
	},
	{ "Balloon", //#211, Qwilfish
		5, 39,
		"The small spikes covering its body\n"
		"developed from scales. They inject a\n"
		"toxin that causes fainting.",
		"",
		0, 430, 0, 256
	},
	{ "Pincer", //#212, Scizor
		18, 1180,
		"Its wings are not used for flying.\n"
		"They are flapped at high speed to adjust\n"
		"its body temperature.",
		"",
		0, 282, 0, 282
	},
	{ "Mold", //#213, Shuckle
		6, 205,
		"It stores Berries inside its shell.\n"
		"To avoid attacks, it hides beneath rocks\n"
		"and remains completely still.",
		"",
		0, 485, 16, 256
	},
	{ "Single Horn", //#214, Heracross
		15, 540,
		"Usually docile, but if disturbed while\n"
		"sipping honey, it chases off the intruder\n"
		"with its horn.",
		"",
		0, 285, 0, 283
	},
	{ "Sharp Claw", //#215, Sneasel
		9, 280,
		"Vicious in nature, it drives PIDGEY from\n"
		"their nests and feasts on the eggs that\n"
		"are left behind.",
		"",
		0, 413, -3, 256
	},
	{ "Little Bear", //#216, Teddiursa
		6, 88,
		"Before food becomes scarce in wintertime,\n"
		"its habit is to hoard food in many hidden\n"
		"locations.",
		"",
		0, 455, 17, 256
	},
	{ "Hibernator", //#217, Ursaring
		18, 1258,
		"With its ability to distinguish any smell,\n"
		"it unfailingly finds all food buried deep\n"
		"underground.",
		"",
		0, 275, 0, 280
	},
	{ "Lava", //#218, Slugma
		7, 350,
		"A common sight in volcanic areas, it\n"
		"slowly slithers around in a constant\n"
		"search for warm places.",
		"",
		0, 329, 14, 256
	},
	{ "Lava", //#219, Magcargo
		8, 550,
		"Its brittle shell occasionally spouts\n"
		"intense flames that circulate throughout\n"
		"its body.",
		"",
		0, 332, 14, 256
	},
	{ "Pig", //#220, Swinub
		4, 65,
		"If it smells something enticing, it dashes\n"
		"off headlong to find the source of the\n"
		"aroma.",
		"",
		0, 324, 19, 256
	},
	{ "Swine", //#221, Piloswine
		11, 558,
		"If it charges at an enemy, the hairs on\n"
		"its back stand up straight. It is very\n"
		"sensitive to sound.",
		"",
		0, 306, 8, 256
	},
	{ "Coral", //#222, Corsola
		6, 50,
		"In a south sea nation, the people live in\n"
		"communities that are built on groups of\n"
		"these "POKEMON".",
		"",
		0, 410, 15, 256
	},
	{ "Jet", //#223, Remoraid
		6, 120,
		"Using its dorsal fin as a suction pad, it\n"
		"clings to a Mantine's underside to\n"
		"scavenge for leftovers.",
		"",
		0, 316, 4, 256
	},
	{ "Jet", //#224, Octillery
		9, 285,
		"It instinctively sneaks into rocky holes.\n"
		"If it gets sleepy, it steals the nest of a\n"
		"fellow Octillery.",
		"",
		0, 296, 9, 256
	},
	{ "Delivery", //#225, Delibird
		9, 160,
		"It nests at the edge of sharp cliffs.\n"
		"It spends all day carrying food to its\n"
		"awaiting chicks.",
		"",
		0, 293, 8, 256
	},
	{ "Kite", //#226, Mantine
		21, 2200,
		"Swimming freely in open seas, it may fly\n"
		"out of the water and over the waves if it\n"
		"builds up enough speed.",
		"",
		0, 275, 0, 360
	},
	{ "Armor Bird", //#227, Skarmory
		17, 505,
		"After nesting in bramble bushes, the wings\n"
		"of its chicks grow hard from scratches by\n"
		"thorns.",
		"",
		0, 285, 0, 276
	},
	{ "Dark", //#228, Houndour
		6, 108,
		"To corner prey, they check each other's\n"
		"location using barks that only they can\n"
		"understand.",
		"",
		0, 393, 15, 256
	},
	{ "Dark", //#229, Houndoom
		14, 350,
		"Upon hearing its eerie howls, other\n"
		""POKEMON" get the shivers and head straight\n"
		"back to their nests.",
		"",
		0, 256, 2, 256
	},
	{ "Dragon", //#230, Kingdra
		18, 1520,
		"It sleeps deep on the ocean floor to\n"
		"build its energy. It is said to cause\n"
		"tornadoes as it wakes.",
		"",
		0, 257, 1, 293
	},
	{ "Long Nose", //#231, Phanpy
		5, 335,
		"As a sign of affection, it bumps with its\n"
		"snout. However, it is so strong, it may\n"
		"send you flying.",
		"",
		0, 465, 20, 256
	},
	{ "Armor", //#232, Donphan
		11, 1200,
		"The longer and bigger its tusks, the\n"
		"higher its rank in its herd. The tusks take\n"
		"a long time to grow.",
		"",
		0, 313, 9, 256
	},
	{ "Virtual", //#233, Porygon2
		6, 325,
		"It was programmed in Visual Basic.",
		"",
		0, 320, 15, 256
	},
	{ "Big Horn", //#234, Stantler
		14, 712,
		"Those who stare at its antlers will\n"
		"gradually lose control of their senses\n"
		"and be unable to stand.",
		"",
		0, 277, -1, 277
	},
	{ "Painter", //#235, Smeargle
		12, 580,
		"By mixing and matching different moves,\n"
		"Smeargle can become a though foe.",
		"",
		0, 287, 5, 256
	},
	{ "Scuffle", //#236, Tyrogue
		7, 210,
		"Even though it is small, it can't be\n"
		"ignored because it will slug any handy\n"
		"target without warning.",
		"",
		0, 292, 8, 256
	},
	{ "Handstand", //#237, Hitmontop
		14, 480,
		"It launches kicks while spinning. If it\n"
		"spins at high speed, it may bore its way\n"
		"into the ground.",
		"",
		0, 256, 2, 257
	},
	{ "Kiss", //#238, Smoochum
		4, 60,
		"It always rocks its head slowly backwards\n"
		"and forwards as if it is trying to kiss\n"
		"someone.",
		"",
		0, 440, 19, 256
	},
	{ "Electric", //#239, Elekid
		6, 235,
		"Even in the most vicious storm, this\n"
		""POKEMON" plays happily if thunder rumbles\n"
		"in the sky.",
		"",
		0, 363, 13, 256
	},
	{ "Live Coal", //#240, Magby
		7, 214,
		"It is found in volcanic craters. Its body\n"
		"heat exceeds 600°C, so don't\n"
		"underestimate it.",
		"",
		0, 284, 11, 256
	},
	{ "Milk Cow", //#241, Miltank
		12, 755,
		"If it has just had a baby, the milk it\n"
		"produces contains much more nutrition than\n"
		"usual.",
		"",
		0, 280, 3, 256
	},
	{ "Happiness", //#242, Blissey
		15, 468,
		"It has a very compassionate nature. If it\n"
		"sees a sick "POKEMON", it will nurse the\n"
		"sufferer back to health.",
		"",
		0, 256, 3, 310
	},
	{ "Thunder", //#243, Raikou
		19, 1780,
		"This "POKEMON" races across the\n"
		"land while barking a cry that sounds\n"
		"like crashing thunder.",
		"",
		0, 283, 0, 359
	},
	{ "Volcano", //#244, Entei
		21, 1980,
		"A "POKEMON" that races across the land.\n"
		"It is said that one is born every time a\n"
		"new volcano appears.",
		"",
		0, 283, 0, 370
	},
	{ "Aurora", //#245, Suicune
		20, 1870,
		"This "POKEMON" races across the land.\n"
		"It is said that north winds will somehow\n"
		"blow whenever it appears.",
		"",
		0, 286, 0, 371
	},
	{ "Rock Skin", //#246, Larvitar
		6, 720,
		"It is born deep underground. It can't\n"
		"emerge until it has entirely consumed the\n"
		"soil around it.",
		"",
		0, 472, 16, 256
	},
	{ "Hard Shell", //#247, Pupitar
		12, 1520,
		"Even sealed in its shell, it can move\n"
		"freely. Hard and fast, it has outstanding\n"
		"destructive power.",
		"",
		0, 292, 8, 256
	},
	{ "Armor", //#248, Tyranitar
		20, 2020,
		"Its body can't be harmed by any sort of\n"
		"attack, so it is very eager to make\n"
		"challenges against enemies.",
		"",
		0, 285, 0, 383
	},
	{ "Diving", //#249, Lugia
		52, 2160,
		"This deep-sea "POKEMON" resembles a dragon,\n"
		"but is really a type of bird.",
		"",
		0, 283, 0, 742
	},
	{ "Rainbow", //#250, Ho-oh
		38, 1990,
		"A great multicolored bird. Its Sacred\n"
		"Fire attack can devastate any foe.",
		"",
		0, 283, 0, 620
	},
	{ "Time Travel", //#251, Celebi
		6, 50,
		"Rumors say this "POKEMON" once traveled\n"
		"through time with a now famous "POKEMON"\n"
		"professor.",
		"",
		0, 393, -10, 256
	},
	{ "Wood Gecko", //#277, Treecko
		5, 50,
		"It quickly scales even vertical walls.\n"
		"It senses humidity with its tail to predict\n"
		"the next day's weather.",
		"",
		0, 541, 17, 256
	},
	{ "Wood Gecko", //#278, Grovyle
		9, 216,
		"Its strongly developed thigh muscles\n"
		"give it astounding agility and jumping\n"
		"performance.",
		"",
		0, 360, 5, 256
	},
	{ "Forest", //#279, Sceptile
		17, 522,
		"The leaves on its forelegs are as sharp\n"
		"as swords. It agilely leaps about the\n"
		"branches of trees to strike.",
		"",
		0, 282, -1, 313
	},
	{ "Chick", //#280, Torchic
		4, 25,
		"It has a flame sac inside its belly that\n"
		"perpetually burns. It feels warm if it is\n"
		"hugged.",
		"",
		0, 566, 18, 256
	},
	{ "Young Fowl", //#281, Combusken
		9, 195,
		"It boosts its concentration by emitting\n"
		"harsh cries. Its kicks have outstanding\n"
		"destructive power.",
		"",
		0, 343, 5, 256
	},
	{ "Blaze", //#282, Blaziken
		19, 520,
		"When facing a tough foe, it looses flames\n"
		"from its wrists. Its powerful legs let it\n"
		"jump clear over buildings.",
		"",
		0, 275, -1, 314
	},
	{ "Mud Fish", //#283, Mudkip
		4, 76,
		"The most loved "POKEMON" in the majority of\n"
		"western culture.",
		"People commonly say “so i herd u liek\n"
		"Mudkips?” to one another in internet groups.",
		0, 535, 19, 256
	},
	{ "Mud Fish", //#284, Marshtomp
		7, 280,
		"It is at its best when on muddy ground\n"
		"with poor footing. It quickly overwhelms\n"
		"foes struggling in mud.",
		"",
		0, 340, 7, 256
	},
	{ "Mud Fish", //#285, Swampert
		15, 819,
		"Its arms are rock-hard. With one swing,\n"
		"they can batter down its foe. It makes its\n"
		"nest on beautiful beaches.",
		"",
		0, 276, -1, 282
	},
	{ "Bite", //#286, Poochyena
		5, 136,
		"It has a very tenacious nature. Its acute\n"
		"sense of smell lets it chase a chosen\n"
		"prey without ever losing track.",
		"",
		0, 481, 18, 256
	},
	{ "Bite", //#287, Mightyena
		10, 370,
		"It will always obey the commands of a\n"
		"skilled Trainer. Its behavior arises from\n"
		"its living in packs in ancient times.",
		"",
		0, 359, 9, 256
	},
	{ "Tinyraccoon", //#288, Zigzagoon
		4, 175,
		"A "POKEMON" with abundant curiosity.\n"
		"It shows an interest in everything, so it\n"
		"always zigs and zags.",
		"",
		0, 560, 21, 256
	},
	{ "Rushing", //#289, Linoone
		5, 325,
		"When running in a straight line, it can top\n"
		"100 km/h. However, it has a tough time\n"
		"with curved roads.",
		"",
		0, 321, 5, 256
	},
	{ "Worm", //#290, Wurmple
		3, 36,
		"It lives amidst tall grass and in forests.\n"
		"When attacked, it resists by pointing its\n"
		"venomous spikes at the foe.",
		"",
		0, 711, 22, 256
	},
	{ "Cocoon", //#291, Silcoon
		6, 100,
		"It conserves its energy by moving as\n"
		"little as possible. It awaits evolution\n"
		"while drinking only a little rainwater.",
		"",
		0, 431, 19, 256
	},
	{ "Butterfly", //#292, Beautifly
		10, 284,
		"Despite its appearance, it has an\n"
		"aggressive nature. It attacks by jabbing\n"
		"with its long, thin mouth.",
		"",
		0, 298, -1, 256
	},
	{ "Cocoon", //#293, Cascoon
		7, 115,
		"Its body, which is made of soft silk,\n"
		"hardens over time. When cracks appear,\n"
		"evolution is near.",
		"",
		0, 391, 19, 256
	},
	{ "Poison Moth", //#294, Dustox
		12, 316,
		"It scatters horribly toxic dust when it\n"
		"senses danger. They tend to gather in the\n"
		"glow of streetlamps at night.",
		"",
		0, 269, 1, 256
	},
	{ "Water Weed", //#295, Lotad
		5, 26,
		"It searches about for clean water. If it\n"
		"does not drink water for too long, the\n"
		"leaf on its head wilts.",
		"",
		0, 406, 17, 256
	},
	{ "Jolly", //#296, Lombre
		12, 325,
		"It lives at the water's edge where it is\n"
		"sunny. It sleeps on a bed of water grass\n"
		"by day and becomes active at night.",
		"",
		0, 277, 7, 256
	},
	{ "Carefree", //#297, Ludicolo
		15, 550,
		"The rhythm of bright, festive music\n"
		"activates Ludicolo's cells, making it more\n"
		"powerful.",
		"",
		0, 283, 0, 282
	},
	{ "Acorn", //#298, Seedot
		5, 40,
		"If it remains still, it becomes impossible\n"
		"to distinguish from real nuts. It delights\n"
		"in surprising foraging Pidgey.",
		"",
		0, 472, 20, 256
	},
	{ "Wily", //#299, Nuzleaf
		10, 280,
		"They live in holes bored in large trees.\n"
		"The sound of Nuzleaf's grass flute fills\n"
		"listeners with dread.",
		"",
		0, 299, 8, 256
	},
	{ "Wicked", //#300, Shiftry
		13, 596,
		"A "POKEMON" that was feared as a forest\n"
		"guardian. It can read the foe's mind and\n"
		"take preemptive action.",
		"",
		0, 290, 2, 256
	},
	{ "Tinyswallow", //#304, Taillow
		3, 23,
		"It dislikes cold seasons. They migrate to\n"
		"other lands in search of warmth, flying\n"
		"over 290 kilometers a day.",
		"",
		0, 465, 20, 256
	},
	{ "Swallow", //#305, Swellow
		7, 198,
		"If its two tail feathers are standing at\n"
		"attention, it is proof of good health.\n"
		"It soars elegantly in the sky.",
		"",
		0, 428, 13, 256
	},
	{ "Seagull", //#309, Wingull
		6, 95,
		"It rides upon ocean winds as if it were\n"
		"a glider. In the winter, it hides food\n"
		"around its nest.",
		"",
		0, 295, -2, 256
	},
	{ "Water Bird", //#310, Pelipper
		12, 280,
		"It is a flying transporter that carries\n"
		"small "POKEMON" in its beak. It bobs on the\n"
		"waves to rest its wings.",
		"",
		0, 288, 1, 256
	},
	{ "Feeling", //#392, Ralts
		4, 66,
		"It is highly attuned to the emotions of\n"
		"people and "POKEMON". It hides if it senses\n"
		"hostility.",
		"",
		0, 457, 18, 256
	},
	{ "Emotion", //#393, Kirlia
		8, 202,
		"The cheerful spirit of its Trainer gives\n"
		"it energy for its psychokinetic power.\n"
		"It spins and dances when happy.",
		"",
		0, 354, 10, 256
	},
	{ "Embrace", //#394, Gardevoir
		16, 484,
		"It has the power to predict the future.\n"
		"Its power peaks when it is protecting its\n"
		"Trainer.",
		"",
		0, 277, 0, 276
	},
	{ "Pond Skater", //#311, Surskit
		5, 17,
		"They usually live on ponds, but after an\n"
		"evening shower, they may appear on\n"
		"puddles in towns.",
		"",
		0, 375, 17, 256
	},
	{ "Eyeball", //#312, Masquerain
		8, 36,
		"The antennae have distinctive patterns\n"
		"that look like eyes. When it rains, they\n"
		"grow heavy, making flight impossible.",
		"",
		0, 378, -1, 256
	},
	{ "Mushroom", //#306, Shroomish
		4, 45,
		"It prefers damp places. By day it remains\n"
		"still in the forest shade. It releases\n"
		"toxic powder from its head.",
		"",
		0, 513, 20, 256
	},
	{ "Mushroom", //#307, Breloom
		12, 392,
		"The seeds on its tail are made of toxic\n"
		"spores. It knocks out foes with quick,\n"
		"virtually invisible punches.",
		"",
		0, 324, 6, 256
	},
	{ "Slacker", //#364, Slakoth
		8, 240,
		"It sleeps for 20 hours every day. Making\n"
		"drowsy those that see it is one of\n"
		"its abilities.",
		"",
		0, 291, 16, 256
	},
	{ "Wild Monkey", //#365, Vigoroth
		14, 465,
		"It is always hungry because it won't stop\n"
		"rampaging. Even while it is eating, it\n"
		"can't keep still.",
		"",
		0, 301, 1, 256
	},
	{ "Lazy", //#366, Slaking
		20, 1305,
		"It is the world's most slothful "POKEMON".\n"
		"However, it can exert horrifying power by\n"
		"releasing pent-up energy all at once.",
		"",
		0, 277, 5, 326
	},
	{ "Trainee", //#301, Nincada
		5, 55,
		"Because it lived almost entirely\n"
		"underground, it is nearly blind.\n"
		"It uses its antennae instead.",
		"",
		0, 405, 20, 256
	},
	{ "Ninja", //#302, Ninjask
		8, 120,
		"This "POKEMON" is so quick, it is said to\n"
		"be able to avoid any attack. It loves to\n"
		"feed on tree sap.",
		"",
		0, 383, -9, 256
	},
	{ "Shed", //#303, Shedinja
		8, 12,
		"The hole in the back is the window to this\n"
		""POKEMON"'s soul. If you look inside, your\n"
		"soul will be stolen.",
		"",
		0, 372, -8, 256
	},
	{ "Whisper", //#370, Whismur
		6, 163,
		"It usually murmurs, but starts crying\n"
		"loudly if it senses danger. It stops when\n"
		"its ear covers are shut.",
		"",
		0, 373, 16, 256
	},
	{ "Big Voice", //#371, Loudred
		10, 405,
		"When it stamps its feet and bellows, it\n"
		"generates ultrasonic waves that can blow\n"
		"apart a house.",
		"",
		0, 356, 8, 256
	},
	{ "Loud Noise", //#372, Exploud
		15, 840,
		"It emits a variety of sounds from the \n"
		"holes all over its body. Its loud cries\n"
		"can be heard from over 10 km away.",
		"",
		0, 284, 1, 256
	},
	{ "Guts", //#335, Makuhita
		10, 864,
		"It grows stronger by enduring harsh\n"
		"training. It is a gutsy "POKEMON" that can\n"
		"withstand any attack.",
		"",
		0, 256, 9, 256
	},
	{ "Arm Thrust", //#336, Hariyama
		23, 2538,
		"It stomps on the ground to build power.\n"
		"It can send a 10-ton truck flying with a\n"
		"straight-arm punch.",
		"",
		0, 268, -1, 375
	},
	{ "Polka Dot", //#350, Azurill
		2, 20,
		"It battles by flinging around its tail,\n"
		"which is bigger than its body. The\n"
		"tail is a flotation device in water.",
		"",
		0, 603, 21, 256
	},
	{ "Compass", //#320, Nosepass
		10, 970,
		"Its magnetic nose consistently faces\n"
		"north. Travelers check Nosepass to get\n"
		"their bearings.",
		"",
		0, 256, 9, 289
	},
	{ "Kitten", //#315, Skitty
		6, 110,
		"Although it is very picky on whom it\n"
		"likes or not, it is extremely cute.",
		"Especially when it chases its own\n"
		"tail in rapid circles.",
		0, 492, 18, 256
	},
	{ "Prim", //#316, Delcatty
		11, 326,
		"The favorite of trend-conscious\n"
		"female Trainers, they are used in\n"
		"competition for their style and fur.",
		"",
		0, 322, 9, 256
	},
	{ "Darkness", //#322, Sableye
		5, 110,
		"It feeds on gemstone crystals.\n"
		"In darkness, its eyes sparkle with the\n"
		"glitter of jewels.",
		"",
		0, 451, 15, 256
	},
	{ "Deceiver", //#355, Mawile
		6, 115,
		"It uses its docile-looking face to lull\n"
		"foes into complacency, then bites with its\n"
		"huge, relentless jaws.",
		"",
		0, 466, 15, 256
	},
	{ "Iron Armor", //#382, Aron
		4, 600,
		"It eats iron to build its steel body.\n"
		"It is a pest that descends from mountains\n"
		"to eat bridges and train tracks.",
		"",
		0, 419, 21, 256
	},
	{ "Iron Armor", //#383, Lairon
		9, 1200,
		"It habitually shows off its strength with\n"
		"the size of sparks it creates by ramming\n"
		"its steel body into boulders.",
		"",
		0, 275, 11, 256
	},
	{ "Iron Armor", //#384, Aggron
		21, 3600,
		"It claims a large mountain as its sole\n"
		"territory. It mercilessly thrashes those\n"
		"that violate its space.",
		"",
		0, 274, -1, 374
	},
	{ "Meditate", //#356, Meditite
		6, 112,
		"It never skips its daily yoga training.\n"
		"It heightens its inner strength through\n"
		"meditation.",
		"",
		0, 465, 17, 256
	},
	{ "Meditate", //#357, Medicham
		13, 315,
		"It elegantly avoids attacks with dance-\n"
		"like steps, then launches a devastating\n"
		"blow in the same motion.",
		"",
		0, 298, 2, 256
	},
	{ "Lightning", //#337, Electrike
		6, 152,
		"It stores static electricity in its fur\n"
		"for discharging. It gives off sparks if a\n"
		"storm approaches.",
		"",
		0, 290, 16, 256
	},
	{ "Discharge", //#338, Manectric
		15, 402,
		"It rarely appears before people.\n"
		"It is said to nest where lightning has\n"
		"fallen.",
		"",
		0, 256, 1, 257
	},
	{ "Cheering", //#353, Plusle
		4, 42,
		"It cheers on partners while scattering\n"
		"sparks from its body. It climbs telephone\n"
		"poles to absorb electricity.",
		"",
		0, 515, -9, 256
	},
	{ "Cheering", //#354, Minun
		4, 42,
		"Its dislike of water makes it take shelter\n"
		"under the eaves of houses in rain. It uses\n"
		"pom-poms made of sparks for cheering.",
		"",
		0, 512, -7, 256
	},
	{ "Firefly", //#386, Volbeat
		7, 177,
		"It lives around clean ponds. At night,\n"
		"its rear lights up. It converses with\n"
		"others by flashing its light.",
		"",
		0, 442, -4, 256
	},
	{ "Firefly", //#387, Illumise
		6, 177,
		"It guides Volbeat to draw signs in night\n"
		"skies. There are scientists that study the\n"
		"patterns it creates.",
		"",
		0, 572, -4, 256
	},
	{ "Thorn", //#363, Roselia
		3, 20,
		"Its flowers give off a relaxing fragrance.\n"
		"The stronger its aroma, the healthier\n"
		"the Roselia is.",
		"",
		0, 677, 20, 256
	},
	{ "Stomach", //#367, Gulpin
		4, 103,
		"There is nothing its stomach can't digest.\n"
		"While it is digesting, vile, overpowering\n"
		"gases are expelled.",
		"",
		0, 593, 22, 256
	},
	{ "Poison Bag", //#368, Swalot
		17, 800,
		"It can swallow a tire whole in one gulp.\n"
		"It secretes a horribly toxic fluid from\n"
		"the pores on its body.",
		"",
		0, 256, 5, 345
	},
	{ "Savage", //#330, Carvanha
		8, 208,
		"It lives in massive rivers that course\n"
		"through jungles. It swarms prey that\n"
		"enter its territory.",
		"",
		0, 362, 0, 256
	},
	{ "Brutal", //#331, Sharpedo
		18, 888,
		"The ruffian of the seas, it has fangs that\n"
		"crunch through iron. It swims by jetting\n"
		"water from its rear.",
		"",
		0, 265, 0, 342
	},
	{ "Ball Whale", //#313, Wailmer
		20, 1300,
		"When it sucks in a large volume of\n"
		"seawater, it becomes like a big, bouncy\n"
		"ball. It eats a ton of food daily.",
		"",
		0, 256, 10, 493
	},
	{ "Float Whale", //#314, Wailord
		145, 3980,
		"It is among the largest of all "POKEMON".\n"
		"It herds prey in a pack then swallows the\n"
		"massed prey in one gulp.",
		"",
		0, 276, -1, 1428
	},
	{ "Numb", //#339, Numel
		7, 240,
		"Magma of almost 1200°C courses through\n"
		"its body. When it grows cold, the\n"
		"magma hardens and slows it down.",
		"",
		0, 310, 14, 256
	},
	{ "Eruption", //#340, Camerupt
		19, 2200,
		"If angered, the humps on its back erupt\n"
		"in a shower of molten lava. It lives in\n"
		"the craters of volcanoes.",
		"",
		0, 256, 6, 345
	},
	{ "Coal", //#321, Torkoal
		5, 804,
		"It burns coal inside its shell. If it is\n"
		"attacked, it belches thick, black smoke\n"
		"and flees.",
		"",
		0, 392, 9, 256
	},
	{ "Bounce", //#351, Spoink
		7, 306,
		"It apparently dies if it stops bouncing\n"
		"about. It carries a pearl from Clamperl\n"
		"on its head.",
		"",
		0, 423, 15, 256
	},
	{ "Manipulate", //#352, Grumpig
		9, 715,
		"It can gain control over foes by doing\n"
		"odd dance steps. The black pearls on its\n"
		"forehead are precious gems.",
		"",
		0, 358, 9, 256
	},
	{ "Spot Panda", //#308, Spinda
		11, 50,
		"No two Spinda are said to have identical\n"
		"patterns. It confuses foes with its\n"
		"stumbling motions.",
		"",
		0, 321, 9, 256
	},
	{ "Ant Pit", //#332, Trapinch
		7, 150,
		"It lives in arid deserts. It makes a\n"
		"sloping pit trap in sand where it\n"
		"patiently awaits prey.",
		"",
		0, 298, 15, 256
	},
	{ "Vibration", //#333, Vibrava
		11, 153,
		"It generates ultrasonic waves by violently\n"
		"flapping its wings. After making its prey\n"
		"faint, it melts the prey with acid.",
		"",
		0, 370, 15, 256
	},
	{ "Mystic", //#334, Flygon
		20, 820,
		"It hides itself by kicking up desert sand\n"
		"with its wings. Red covers shield its eyes\n"
		"from sand.",
		"",
		0, 280, 0, 299
	},
	{ "Cactus", //#344, Cacnea
		4, 513,
		"It prefers harsh environments such as\n"
		"deserts. It can survive for 30 days on\n"
		"water stored in its body.",
		"",
		0, 455, 19, 256
	},
	{ "Scarecrow", //#345, Cacturne
		13, 774,
		"It lives in deserts. It becomes active at\n"
		"night when it hunts for prey exhausted\n"
		"from the desert's heat.",
		"",
		0, 327, 3, 256
	},
	{ "Cotton Bird", //#358, Swablu
		4, 12,
		"It constantly grooms its cotton-like\n"
		"wings. It takes a shower to clean\n"
		"itself if it becomes dirty.",
		"",
		0, 422, -8, 256
	},
	{ "Humming", //#359, Altaria
		11, 206,
		"If you hear a beautiful melody trilling\n"
		"deep among mountains far from people,\n"
		"it is Altaria's humming.",
		"",
		0, 327, 0, 256
	},
	{ "Cat Ferret", //#380, Zangoose
		13, 403,
		"If it comes across a Seviper, its fur\n"
		"bristles and it assumes its battle pose.\n"
		"Its sharp claws are its best weapon.",
		"",
		0, 256, 2, 256
	},
	{ "Fang Snake", //#379, Seviper
		27, 525,
		"It sharpens its swordlike tail on hard\n"
		"rocks. It hides in tall grass and strikes\n"
		"unwary prey with venomous fangs.",
		"",
		0, 275, 6, 256
	},
	{ "Meteorite", //#348, Lunatone
		10, 1680,
		"Its health ebbs and flows with the lunar\n"
		"cycle. It brims with power when exposed\n"
		"to the light of the full moon.",
		"",
		0, 300, 1, 256
	},
	{ "Meteorite", //#349, Solrock
		12, 1540,
		"It absorbs solar energy during the day.\n"
		"Always expressionless, it can sense what\n"
		"its foe is thinking.",
		"",
		0, 328, -3, 256
	},
	{ "Whiskers", //#323, Barboach
		4, 19,
		"It probes muddy riverbeds with its two\n"
		"long whiskers. A slimy film protects its\n"
		"body.",
		"",
		0, 581, -2, 256
	},
	{ "Whiskers", //#324, Whiscash
		9, 236,
		"It makes its nest at the bottom of \n"
		"swamps. It will eat anything - if it is\n"
		"alive, Whiscash will eat it.",
		"",
		0, 317, 1, 256
	},
	{ "Ruffian", //#326, Corphish
		6, 115,
		"It came from overseas. It is a very hardy\n"
		"creature that will quickly proliferate,\n"
		"even in polluted streams.",
		"",
		0, 484, 18, 256
	},
	{ "Rogue", //#327, Crawdaunt
		11, 328,
		"A rough customer that wildly flails its\n"
		"giant claws. It is said to be extremely\n"
		"hard to raise.",
		"",
		0, 365, 7, 256
	},
	{ "Clay Doll", //#318, Baltoy
		5, 215,
		"It was discovered in ancient ruins.\n"
		"While moving, it constantly spins. It\n"
		"stands on one foot even when asleep.",
		"",
		0, 384, 18, 256
	},
	{ "Clay Doll", //#319, Claydol
		15, 1080,
		"It appears to have been born from clay\n"
		"dolls made by ancient people. It uses\n"
		"telekinesis to float and move.",
		"",
		0, 256, 3, 280
	},
	{ "Sea Lily", //#388, Lileep
		10, 238,
		"It became extinct roughly 100 million\n"
		"years ago. It was regenerated from a\n"
		"fossil using advanced techniques.",
		"",
		0, 305, 8, 256
	},
	{ "Barnacle", //#389, Cradily
		15, 604,
		"It ensnares prey with its eight tentacles.\n"
		"It then melts the prey with a strong acid\n"
		"before feeding.",
		"",
		0, 275, -1, 269
	},
	{ "Old Shrimp", //#390, Anorith
		7, 125,
		"It is a kind of "POKEMON" progenitor.\n"
		"It uses its extending claws to catch prey\n"
		"hiding among rocks on the seafloor.",
		"",
		0, 296, 4, 256
	},
	{ "Plate", //#391, Armaldo
		15, 682,
		"Protected by a hard shell, its body is\n"
		"very sturdy. It skewers prey with its\n"
		"claws to feed.",
		"",
		0, 312, 2, 271
	},
	{ "Fish", //#328, Feebas
		6, 74,
		"Ridiculed for its shabby appearance,\n"
		"it is ignored by researchers. It lives in\n"
		"ponds choked with weeds.",
		"",
		0, 423, 3, 256
	},
	{ "Tender", //#329, Milotic
		62, 1620,
		"Milotic is breathtakingly beautiful.\n"
		"Those that see it are said to forget their\n"
		"combative spirits.",
		"",
		0, 282, -1, 382
	},
	{ "Weather", //#385, Castform
		3, 8,
		"It has the ability to change its form into\n"
		"the sun, the rain, or a snow cloud, \n"
		"depending on the weather.",
		"",
		0, 435, -5, 256
	},
	{ "Color Swap", //#317, Kecleon
		10, 220,
		"It changes body color to blend in with\n"
		"its surroundings. It also changes color if\n"
		"it is happy or sad.",
		"",
		0, 316, 8, 256
	},
	{ "Puppet", //#377, Shuppet
		6, 23,
		"It loves to feed on feelings like envy and\n"
		"malice. Its upright horn catches the\n"
		"emotions of people.",
		"",
		0, 440, -3, 256
	},
	{ "Marionette", //#378, Banette
		11, 125,
		"Strong feelings of hatred turned a puppet\n"
		"into a "POKEMON". If it opens its mouth,\n"
		"its cursed energy escapes.",
		"",
		0, 262, 9, 256
	},
	{ "Requiem", //#361, Duskull
		8, 150,
		"Making itself invisible, it silently sneaks\n"
		"up to prey. It has the ability to slip\n"
		"through thick walls.",
		"",
		0, 376, 13, 256
	},
	{ "Beckon", //#362, Dusclops
		16, 306,
		"Its body is entirely hollow. When it opens\n"
		"its mouth, it sucks everything in as if it\n"
		"were a black hole.",
		"",
		0, 256, 2, 299
	},
	{ "Fruit", //#369, Tropius
		20, 1000,
		"It lives in tropical jungles. The bunch of\n"
		"fruit around its neck is delicious.\n"
		"The fruit grows twice a year.",
		"",
		0, 283, -1, 371
	},
	{ "Wind Chime", //#411, Chimecho
		6, 10,
		"It travels by riding on winds. It cleverly\n"
		"uses its long tail to pluck nuts and\n"
		"berries, which it loves to eat.",
		"",
		0, 505, -4, 256
	},
	{ "Disaster", //#376, Absol
		12, 470,
		"It appears when it senses an impending\n"
		"natural disaster. As a result, it was\n"
		"mistaken as a doom-bringer.",
		"",
		0, 301, 1, 256
	},
	{ "Bright", //#360, Wynaut
		6, 140,
		"It tends to move in a pack with others.\n"
		"They cluster in a tight group to sleep in\n"
		"a cave.",
		"",
		0, 453, 17, 256
	},
	{ "Snow Hat", //#346, Snorunt
		7, 168,
		"It is said that a home visited by a\n"
		"Snorunt will prosper. It can withstand\n"
		"cold of minus -100°C.",
		"",
		0, 380, 14, 256
	},
	{ "Face", //#347, Glalie
		15, 2565,
		"It has a body of ice that won't melt,\n"
		"even with fire. It can instantly freeze\n"
		"moisture in the atmosphere.",
		"",
		0, 256, 3, 344
	},
	{ "Clap", //#341, Spheal
		8, 395,
		"Its body is covered in fluffy fur. The\n"
		"fur keeps it from feeling cold while\n"
		"it is rolling on ice.",
		"",
		0, 315, 15, 256
	},
	{ "Ball Roll", //#342, Sealeo
		11, 876,
		"It touches new things with its nose to\n"
		"test for smell and feel. It plays by\n"
		"spinning Spheal on its nose.",
		"",
		0, 338, 12, 256
	},
	{ "Ice Break", //#343, Walrein
		14, 1506,
		"It swims through icy seas while shattering\n"
		"ice floes with its large tusks. It is\n"
		"protected by its thick blubber.",
		"",
		0, 305, 2, 277
	},
	{ "Bivalve", //#373, Clamperl
		4, 525,
		"It is protected by a sturdy shell.\n"
		"Once in a lifetime, it makes a magnificent\n"
		"pearl.",
		"",
		0, 691, 22, 256
	},
	{ "Deep Sea", //#374, Huntail
		17, 270,
		"It lives deep in the sea where no light\n"
		"ever filters down. It lights up its small\n"
		"fishlike tail to attract prey.",
		"",
		0, 307, 1, 256
	},
	{ "South Sea", //#375, Gorebyss
		18, 226,
		"Its swimming form is exquisitely elegant.\n"
		"With its thin mouth, it feeds on seaweed\n"
		"that grows between rocks.",
		"",
		0, 278, 5, 256
	},
	{ "Longevity", //#381, Relicanth
		10, 234,
		"It has remained unchanged for 100\n"
		"million years. It was discovered\n"
		"during a deep-sea exploration.",
		"",
		0, 316, 5, 256
	},
	{ "Rendezvous", //#325, Luvdisc
		6, 87,
		"During the spawning season, countless\n"
		"Luvdisc congregate at coral reefs,\n"
		"turning the waters pink.",
		"",
		0, 371, 2, 256
	},
	{ "Rock Head", //#395, Bagon
		6, 421,
		"Its steel-hard head can shatter boulders.\n"
		"It longingly hopes for wings to grow so it\n"
		"can fly.",
		"",
		0, 448, 17, 256
	},
	{ "Endurance", //#396, Shelgon
		11, 1105,
		"Its armored body makes all attacks bounce\n"
		"off. The armor is too tough, however,\n"
		"making it heavy and somewhat sluggish.",
		"",
		0, 311, 10, 256
	},
	{ "Dragon", //#397, Salamence
		15, 1026,
		"It becomes uncontrollable if it is\n"
		"enraged. It destroys everything with\n"
		"shredding claws and fire.",
		"",
		0, 272, 2, 307
	},
	{ "Iron Ball", //#398, Beldum
		6, 952,
		"It uses magnetic waves to converse with\n"
		"its kind. All the cells in its body are\n"
		"magnetic.",
		"",
		0, 414, -1, 256
	},
	{ "Iron Claw", //#399, Metang
		12, 2025,
		"It floats midair using magnetism. Its body\n"
		"is so tough, even a crash with a jet\n"
		"plane won't leave a scratch.",
		"",
		0, 256, 3, 272
	},
	{ "Iron Leg", //#400, Metagross
		16, 5500,
		"It is formed by two Metang fusing.\n"
		"Its four brains are said to be superior\n"
		"to a supercomputer.",
		"",
		0, 272, 3, 461
	},
	{ "Rock Peak", //#401, Regirock
		17, 2300,
		"It is entirely composed of rocks with no\n"
		"sign of a brain or heart. It is a mystery\n"
		"even to modern scientists.",
		"",
		0, 256, 1, 309
	},
	{ "Iceberg", //#402, Regice
		18, 1750,
		"Research revealed that its body is made\n"
		"of the same kind of ice that is found at\n"
		"the South Pole.",
		"",
		0, 265, 0, 317
	},
	{ "Iron", //#403, Registeel
		19, 2050,
		"It is sturdier than any kind of metal.\n"
		"It hardened due to pressure underground\n"
		"over tens of thousands of years.",
		"",
		0, 256, 0, 359
	},
	{ "Eon", //#407, Latias
		14, 400,
		"It can telepathically communicate with\n"
		"people. It changes its appearance using\n"
		"its down that refracts light.",
		"",
		0, 291, 2, 256
	},
	{ "Eon", //#408, Latios
		20, 600,
		"It has a docile temperament and dislikes\n"
		"fighting. Tucking in its forelegs, it can\n"
		"fly faster than a jet plane.",
		"",
		0, 273, 0, 313
	},
	{ "Sea Basin", //#404, Kyogre
		45, 3520,
		"This "POKEMON" is said to have\n"
		"expanded the sea by bringing heavy rains.\n"
		"It has the power to control water.",
		"",
		0, 272, 1, 639
	},
	{ "Continent", //#405, Groudon
		35, 9500,
		"This legendary "POKEMON" is said to\n"
		"represent the land. It went to sleep after\n"
		"dueling Kyogre.",
		"",
		0, 276, 0, 530
	},
	{ "Sky High", //#406, Rayquaza
		70, 2065,
		"Living in the ozone layer for quite a\n"
		"long time, one has to wonder if humanity\n"
		"has angered it with pollution…",
		"",
		0, 286, -1, 483
	},
	{ "Wish", //#409, Jirachi
		3, 11,
		"It is said to make any wish come true.\n"
		"It is awake for only seven days out of\n"
		"a thousand years.",
		"",
		0, 608, -8, 256
	},
	{ "DNA", //#410, Deoxys
		17, 608,
		"This mysterious "POKEMON" came about as the\n"
		"result of alien DNA exposed to a space\n"
		"virus.",
		"",
		0, 293, 0, 337
	},
};
