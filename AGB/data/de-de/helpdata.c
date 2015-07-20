//======================================================================
//
//  OpenPoké help system contents
//
//  Time-stamp: 2008-05-09, 11:32:43
//  (comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../../openpoke.h"

const aHelpList help_index[]; //predeclared to allow forward referencing

const aHelpListPage help_content[] =
{
	{ //0, "content_00D"
		"I'm playing for the first time. Help!",
		"You become the main character,\n"
		"exploring the world of "POKEMON".\n"
		"By talking to people and solving\n"
		"mysteries, new paths will open to you.\n"
		"Strive for the goal together with your\n"
		"wonderful "POKEMON"."
	},
	{ //1, "content_00E"
		"What should I be doing?",
		"When you come across another person,\n"
		"go up to them and press the A Button.\n"
		"That will get them to talk and interact\n"
		"with your character. You may also\n"
		"examine various items and objects in\n"
		"the same way. Talk to people and check\n"
		"things often to obtain information."
	},
	{ //2, "content_00F"
		"I can't get out of a room!",
		"On the stairs or the exits of a\n"
		"building is a red mat. Move your\n"
		"character to stand on top of the\n"
		"red mat. Press the + Control Pad \n"
		"toward the stairs or the exit to\n"
		"advance."
	},
	{ //3, "content_010"
		"I can't find the person I want.",
		"This isn't something you should worry\n"
		"about too much.\n"
		"Talk to other people, check signs,\n"
		"check things, and so on.\n"
		"Sometimes, you may need to just move\n"
		"to a new town or place."
	},
	{ //4, "content_011"
		"I've talked to everyone. Now what?",
		"Try moving on to a new road, town, or\n"
		"place."
	},
	{ //5, "content_012"
		"There's someone blocking my way!",
		"There could be something in the town\n"
		"or inside a building that is the cause.\n"
		"Try talking to the people in the area\n"
		"again. If there is a problem that they\n"
		"need solved, you may have to help.\n"
		"Afterwards, try talking to the person\n"
		"blocking your way again."
	},
	{ //6, "content_013"
		"I can't go on!",
		"Try talking to people by going up to\n"
		"them and pressing the A Button.\n"
		"Also, try checking things like odd trees\n"
		"and strange rocks with the A Button.\n"
		"Press the + Control Pad and try going\n"
		"to places that look impassable, too."
	},
	{ //7, "content_014"
		"I'm out of things to do.",
		"Try going to places where you \n"
		"haven't visited yet.\n"
		"Also, check everything that looks\n"
		"suspicious by pressing the A Button."
	},
	{ //8, "content_015"
		"What happened to the item I got?",
		"Any item that you are given by another\n"
		"character goes in your bag.\n"
		"The item is automatically sorted and\n"
		"placed in one of three pockets.\n"
		"For instructions on the bag's use,\n"
		"please refer to the Help System's\n"
		"“How do I do this?” heading."
	},
	{ //9, "content_016"
		"What are the basics of my adventure?",
		"If "POKEMON" are hurt in battle,\n"
		"take them to a "POKEMON" Center and\n"
		"have them healed by the staff.\n"
		"Get in the habit of saving your\n"
		"game and recording your progress.\n"
		"Stock up on healing items at\n"
		""POKEMON" Marts before traveling far."
	},
	{ //10, "content_017"
		"How are roads and forests different?",
		"Forests are basically the same as\n"
		"roads but they can be like mazes.\n"
		"All forests have a way out, so don't\n"
		"give up if you get lost."
	},
	{ //11, "content_018"
		"How are caves different?",
		"Caves are dark and dangerous. Wild\n"
		""POKEMON" can appear anywhere in them.\n"
		"If there is an emergency, rush to a\n"
		""POKEMON" Center or use items.\n"
		"New towns await discovery beyond some\n"
		"caves, so don't give up."
	},
	{ //12, "content_019"
		"How do I progress?",
		"The object of the game is to train\n"
		"your "POKEMON" and move forward.\n"
		"You must collect info and solve\n"
		"problems. For example, what do you\n"
		"need to get around an obstacle?\n"
		"What would get that impeding\n"
		"person out of the way?"
	},
	{ //13, "content_01A"
		"When can I use items?",
		"There are several kinds of items.\n"
		"Some can be used only on the field.\n"
		"Some are only for use during battle.\n"
		"Some can be used anytime.\n"
		"Try using an item - if it can't be used,\n"
		"you will be alerted."
	},
	{ //14, "content_01B"
		"What's a battle?",
		"In a battle, "POKEMON" try to reduce\n"
		"one another's vitality, expressed as\n"
		"HP. If a "POKEMON"'s HP falls to zero,\n"
		"it faints, and the other "POKEMON"\n"
		"wins. By winning a battle, "POKEMON"\n"
		"earn EXP. Points, which help them\n"
		"level up (grow stronger)."
	},
	{ //15, "content_01C"
		"How do I prepare for battle?",
		"First, fully heal the "POKEMON" in your\n"
		"party (the "POKEMON" with you) at any\n"
		""POKEMON" Center.\n"
		"You should also buy healing items for\n"
		"emergencies at a "POKEMON" Mart."
	},
	{ //16, "content_01D"
		"What is a "POKEMON"'s vitality?",
		"A "POKEMON"'s vitality is expressed in HP.\n"
		"If a "POKEMON" is hurt in battle, HP is\n"
		"subtracted. If its HP drops to zero,\n"
		"the "POKEMON" faints.\n"
		"Heal hurt or fainted "POKEMON" at a\n"
		""POKEMON" Center or by using items."
	},
	{ //17, "content_01E"
		"My "POKEMON" are hurt!",
		"A "POKEMON" Center is like an inn for\n"
		""POKEMON". It will fully heal "POKEMON" of\n"
		"any status problems and fully restore\n"
		"their HP using a special machine.\n"
		"This service is free, so get in the\n"
		"habit of healing your "POKEMON" often."
	},
	{ //18, "content_01F"
		"What is a status problem?",
		"A status problem refers to an ailment\n"
		"that is inflicted on a "POKEMON" by its\n"
		"foe's attack. These include burns,\n"
		"paralysis, poisoning, sleep, and\n"
		"freezing. These can be healed by\n"
		"visiting a "POKEMON" Center or using\n"
		"the appropriate item."
	},
	{ //19, "content_020"
		"What happens if all my "POKEMON" faint?",
		"If all the "POKEMON" in your party\n"
		"(all the "POKEMON" with you) faint, you\n"
		"lose some MONEY, and you are\n"
		"returned home or to a "POKEMON"\n"
		"Center. To reduce that chance, visit\n"
		""POKEMON" Centers often. Also, get\n"
		"in the habit of saving often."
	},
	{ //20, "content_021"
		"I can't catch "POKEMON"!",
		"If a wild "POKEMON" escapes from a "POKE"\n"
		"Ball, it's obviously still feisty.\n"
		"Try reducing its HP some more, and\n"
		"try to weaken it with paralysis or sleep\n"
		"before trying to catch it.\n"
		"If the "POKE" Ball rocks for a while,\n"
		"the quarry is close to being caught!"
	},
	{ //21, "content_022"
		"I ran out of POTIONS.",
		"There are shops, known as "POKEMON"\n"
		"Marts, that sell items.\n"
		"You will not find "POKEMON" Marts on\n"
		"roads, in forests, or in caves.\n"
		"Stock up on needed items while you are\n"
		"visiting a town with a "POKEMON" Mart."
	},
	{ //22, "content_023"
		"Can I buy "POKE" Balls?",
		"You may buy "POKE" Balls at any\n"
		""POKEMON" Mart in any town.\n"
		"You will not find "POKEMON" Marts on\n"
		"roads, in forests, or in caves.\n"
		"Stock up on "POKE" Balls while you are\n"
		"visiting a town with a "POKEMON" Mart."
	},
	{ //23, "content_024"
		"What's a Trainer?",
		"A Trainer is a person who raises\n"
		""POKEMON" through battling.\n"
		"Trainers will challenge you \n"
		"wherever they are - it could be on\n"
		"a road, in forests, caves, anywhere.\n"
		"If your eyes meet, you have to accept\n"
		"their challenge. So be careful!"
	},
	{ //24, "content_025"
		"How do I win against a Trainer?",
		"To beat a Trainer in battle, use\n"
		""POKEMON" that have type advantages\n"
		"over the foe's "POKEMON". You may also\n"
		"use highly trained "POKEMON" with\n"
		"overwhelming power. Outnumbering the\n"
		"foe's "POKEMON" is another obvious\n"
		"tactic."
	},
	{ //25, "content_026"
		"Where do "POKEMON" appear?",
		"Wild "POKEMON" will appear in tall grass,\n"
		"on roads, and in forests. They will\n"
		"appear anywhere in dark caves.\n"
		"There are no wild "POKEMON" or Trainers\n"
		"in towns, so they are safe places."
	},
	{ //26, "content_027"
		"What are "POKEMON" moves?",
		""POKEMON" may learn up to four different\n"
		"techniques, or moves. There is a great\n"
		"variety of moves including attacks and\n"
		"those with special effects. The kinds\n"
		"of moves that can be learned vary\n"
		"for each "POKEMON". Some moves\n"
		"can be learned from machines."
	},
	{ //27, "content_028"
		"What are Hidden Moves?",
		"Hidden Moves are those that are\n"
		"especially important for your\n"
		"adventure. To use such a move outside\n"
		"of battle, open the “"POKEMON"” menu\n"
		"and make the "POKEMON" that knows the\n"
		"move use it. A fainted "POKEMON" may use\n"
		"a Hidden Move outside of battle."
	},
	{ //28, "content_029"
		"What moves should I use?",
		"Select “Fight,” and the menu of moves\n"
		"will appear. Consider the type\n"
		"matchups, and use the most effective\n"
		"moves. You can check the effects of\n"
		"moves by opening “"POKEMON",”\n"
		"picking a "POKEMON", opening “Summary,”\n"
		"then opening “"POKEMON" Skills.”"
	},
	{ //29, "content_02A"
		"I want to add more moves.",
		"The most a "POKEMON" can learn is four\n"
		"moves. They are learned as the\n"
		""POKEMON" levels up. It can also be\n"
		"taught a move using a TM (Technical\n"
		"Machine) or HM (Hidden Machine).\n"
		"There are also people who teach moves."
	},
	{ //30, "content_02B"
		"I want to make my "POKEMON" stronger.",
		"The key to making your "POKEMON"\n"
		"strong is to battle and win often.\n"
		"The EXP. (Experience) Points earned\n"
		"by winning battles accumulate to\n"
		"level up "POKEMON" that participated in\n"
		"them. Battle wild "POKEMON" often to\n"
		"level up your party."
	},
	{ //31, "content_02C"
		"The foe "POKEMON" are too strong!",
		"If your foes are too strong, try\n"
		"leveling up your "POKEMON" some more.\n"
		"Go back the way you came and battle\n"
		"wild "POKEMON" to level up your party.\n"
		"You may also battle Trainers whom you\n"
		"have not battled before."
	},
	{ //32, "content_02D"
		"What do I do in a cave?",
		"Unlike roads and forests, wild "POKEMON"\n"
		"can appear anywhere in caves.\n"
		"If your "POKEMON" are hurt in a cave,\n"
		"rush to a "POKEMON" Center or use items\n"
		"to heal them right away. It is very\n"
		"dangerous to force your luck in caves."
	},
	{ //33, "content_02E"
		"There's nothing that I want to know!",
		"Trust your own knowledge and power.\n"
		"Believe in yourself and find your way!"
	},
	{ //34, "content_02F"
		"What's a "POKEMON" Center?",
		"A "POKEMON" Center is identified by its\n"
		"red roof and a “P.C” sign. Every\n"
		""POKEMON" Center offers such services as\n"
		"fully healing "POKEMON" and free PC use,\n"
		"making it essential for your travels.\n"
		"On the upper floor are facilities for\n"
		"linking with friends and others."
	},
	{ //35, "content_030"
		"What's a "POKEMON" Mart?",
		"A "POKEMON" Mart is identified by its\n"
		"blue roof and a “Mart” sign.\n"
		"Items can be bought and sold at any\n"
		""POKEMON" Mart. Some Marts carry items\n"
		"that are available only in their towns."
	},
	{ //36, "content_031"
		"I want to end the game.",
		"You can safely end your game by\n"
		"selecting “Save” on the menu.\n"
		"Once you have saved, the game can be\n"
		"safely turned off. When the game is\n"
		"turned back on, you can resume from\n"
		"where you last saved."
	},
	{ //37, "content_032"
		"What's a "POKEMON"?",
		""POKEMON" are living beings about which\n"
		"many mysteries still remain. You may\n"
		"see them in grass, the sea, and caves.\n"
		"They appear to obey the wishes of the\n"
		"Trainers that caught them."
	},
	{ //38, "content_033"
		"What is that person like?",
		"Use the Fame Checker among the\n"
		"key items in your bag.\n"
		"It may give you a hint, so try it out."
	},
	{ //39, "content_034"
		"What does a Hidden Move do?",
		"A Hidden Move is taught to a "POKEMON"\n"
		"using an HM (Hidden Machine).\n"
		"A Hidden Move is important for helping\n"
		"your adventure. For example, one is\n"
		"used to light up dark caves. Another\n"
		"cuts down small trees. There is one\n"
		"for traveling on water, and so on."
	},
	{ //40, "content_035"
		"What do I do in a Safari Game?",
		"Try to catch wild "POKEMON" by throwing\n"
		"the special Safari Balls.\n"
		"You may keep any item you find, too."
	},
	{ //41, "content_036"
		"What are the Safari Game rules?",
		"Your Safari Game ends once you have\n"
		"traveled a certain distance or thrown\n"
		"all your Safari Balls.\n"
		"Open the menu to check the remaining\n"
		"number of steps and Safari Balls."
	},
	{ //42, "content_037"
		"I want to end this Safari Game!",
		"If you would like to cut your Safari\n"
		"Game short, open the menu and select\n"
		"“Retire” at the top of the list."
	},
	{ //43, "content_038"
		"What is a Gym?",
		""POKEMON" GymS are operated by the\n"
		""POKEMON" League and are training\n"
		"facilities for Trainers. They are all\n"
		"across the land in cities and towns.\n"
		"Each one is headed by a Leader, who\n"
		"is a very skilled Trainer. Beat the\n"
		"Leader to collect a badge."
	},
	{ //44, "content_067"
		"Using “"POKE"Dex”",
		"\x80\x03 Select “"POKE"Dex” on the menu.\n"
		"\x80\x04 Choose "POKEMON" using commands such\n"
		"   as “"POKEMON" List,”\n"
		"   “Habitats of "POKEMON",” and\n"
		"   “Search.”\n"
		"\x80\x05 Select a "POKEMON" to obtain detailed\n"
		"   information."
	},
	{ //45, "content_068"
		"Using “"POKEMON"”",
		"\x80\x03 Select “"POKEMON"” on the menu.\n"
		"\x80\x04 Choose a "POKEMON" in your party.\n"
		"\x80\x05 Select “Summary,” “Switch,”\n"
		"   or “Item.”"
	},
	{ //46, "content_069"
		"Using “Summary”",
		"\x80\x03 Select “Summary.”\n"
		"\x80\x04 Press left or right on the + Control\n"
		"   Pad to check the information:\n"
		"   “"POKEMON" Info”\n"
		"   “"POKEMON" Skills”\n"
		"   “Known Moves”"
	},
	{ //47, "content_06A"
		"Using “Switch”",
		"\x80\x03 Choose the "POKEMON" you want to\n"
		"   switch around.\n"
		"\x80\x04 Select “Switch.”\n"
		"\x80\x05 Select the "POKEMON" to switch with\n"
		"   the first one.\n"
		"The "POKEMON" at the left of the screen\n"
		"will be the first one out in a battle."
	},
	{ //48, "content_06B"
		"Using “Item”",
		"\x80\x03 Select “Item.”\n"
		"\x80\x04 Select whether you want to give\n"
		"   an item to the "POKEMON" to hold,\n"
		"   or take an item it is holding.\n"
		"A "POKEMON" can hold no more than one\n"
		"item!"
	},
	{ //49, "content_06C"
		"Using “Bag”",
		"\x80\x03 Select “Bag” on the menu.\n"
		"\x80\x04 Press left or right on the + Control\n"
		"   Pad to check the data headings:\n"
		"   “Items”\n"
		"   “Key Items”\n"
		"   “"POKE" Balls”\n"
		"   Press up or down to select an item."
	},
	{ //50, "content_06D"
		"Using an item",
		"\x80\x03 Select the “Items” pocket.\n"
		"\x80\x04 Press up or down on the + Control\n"
		"   Pad to select an item.\n"
		"\x80\x05 Select “Use” to use the selected\n"
		"   item.\n"
		"Some items may not be used depending\n"
		"on the place and/or situation."
	},
	{ //51, "content_06E"
		"Using a key item",
		"\x80\x03 Select the “Key Items” pocket.\n"
		"\x80\x04 Press up or down on the + Control\n"
		"   Pad to select a key item.\n"
		"\x80\x05 Select “Use” to use the selected\n"
		"   key item."
	},
	{ //52, "content_06F"
		"Using a "POKE" Ball",
		"\x80\x03 While battling a wild "POKEMON",\n"
		"   select the Bag's “"POKE" Balls”\n"
		"   pocket.\n"
		"\x80\x04 Press up or down on the + Control\n"
		"   Pad to select a "POKE" Ball.\n"
		"\x80\x05 Select “Use” to throw the selected\n"
		"   "POKE" Ball."
	},
	{ //53, "content_070"
		"Using “\x1F\x01”",
		"\x80\x03 Select “\x1F\x01” on the menu.\n"
		"\x80\x04 Your Trainer Card is displayed face\n"
		"   up with basic information. Press the\n"
		"   A Button to turn the card over.\n"
		"\x80\x05 A variety of data can be found on\n"
		"   the reverse side of the card."
	},
	{ //54, "content_071"
		"Using “Save”",
		"\x80\x03 Select “Save” on the menu.\n"
		"\x80\x04 Select “Yes” and your progress is\n"
		"   recorded in the save file.\n"
		"Once the game is saved, you may turn\n"
		"off the game. Your game can be resumed\n"
		"from where you saved."
	},
	{ //55, "content_072"
		"Using “Option”",
		"\x80\x03 Select “Option” on the menu.\n"
		"\x80\x04 Press up or down on the + Control\n"
		"   Pad to select an optional item, then\n"
		"   press left or right to alter the\n"
		"   settings.\n"
		"\x80\x05 Select “Cancel” or press the\n"
		"   B Button after making changes."
	},
	{ //56, "content_073"
		"Using a Potion",
		"\x80\x03 Open the menu.\n"
		"\x80\x04 Press up or down on the + Control\n"
		"   Pad and select “Bag.”\n"
		"\x80\x05 Select “Potion” in the “Items”\n"
		"   pocket.\n"
		"\x80\x06 Select “Use.”\n"
		"\x80\x07 Select the "POKEMON" to be healed."
	},
	{ //57, "content_074"
		"Using the Town Map",
		"\x80\x03 Open the menu.\n"
		"\x80\x04 Press up or down on the + Control\n"
		"   Pad and select “Bag.”\n"
		"\x80\x05 Press left or right to open the\n"
		"   “Key Items” pocket, then press\n"
		"   up or down to select “Town Map.” \n"
		"\x80\x06 Select “Use” to open the Town Map."
	},
	{ //58, "content_075"
		"Using a TM",
		"\x80\x03 Open the menu.\n"
		"\x80\x04 Open the “Key Items” pocket in the\n"
		"   “Bag.”\n"
		"\x80\x05 Open the TM Case.\n"
		"\x80\x06 Select and use a TM.\n"
		"\x80\x07 Select a "POKEMON" that can learn the\n"
		"   move in the TM."
	},
	{ //59, "content_076"
		"Using an HM",
		"\x80\x03 Open the menu.\n"
		"\x80\x04 Open the “Key Items” pocket in the\n"
		"   “Bag.”\n"
		"\x80\x05 Open the TM Case.\n"
		"\x80\x06 Select and use an HM.\n"
		"\x80\x07 Select a "POKEMON" that can learn it.\n"
		"HMs are hard to remove, so be careful!"
	},
	{ //60, "content_077"
		"Using a move outside of battle",
		"\x80\x03 Open the menu.\n"
		"\x80\x04 Select “"POKEMON".”\n"
		"\x80\x05 Select a "POKEMON" that knows an\n"
		"   HM move. The usable HM move(s)\n"
		"   will be shown in blue. Select and\n"
		"   use the desired move to destroy an\n"
		"   obstacle, fly, surf, etc."
	},
	{ //61, "content_078"
		"Riding the Bicycle",
		"\x80\x03 Open the menu. Open the\n"
		"   “Key Items” pocket in the “Bag”\n"
		"   and select the Bicycle.\n"
		"\x80\x04 The Bicycle can be ridden by\n"
		"   selecting “Use.” You may also\n"
		"   register it for instant use by\n"
		"   pressing SELECT."
	},
	{ //62, "content_079"
		"Entering a name",
		"\x80\x03 Move the cursor to the letter you\n"
		"   want with the + Control Pad, then\n"
		"   press the A Button to enter it.\n"
		"\x80\x04 Press the B Button to back up.\n"
		"\x80\x05 Press SELECT to switch between\n"
		"   uppercase and lowercase letters.\n"
		"\x80\x06 Press the A Button on “OK.”"
	},
	{ //63, "content_07A"
		"Using a PC",
		"\x80\x03 Go to any "POKEMON" Center, go up\n"
		"   to the PC, then press the A Button."
	},
	{ //64, "content_07B"
		"Using “(?)'S PC”",
		"\x80\x03 Select “(?)'S PC” on the PC.\n"
		"\x80\x04 Select from one of the top three\n"
		"   menu items to access the "POKEMON"\n"
		"   Storage System.\n"
		"If you catch a "POKEMON" when you have\n"
		"six in your party, the "POKEMON" is sent\n"
		"automatically to a BOX in the System!"
	},
	{ //65, "content_07C"
		"Using “Withdraw”",
		"\x80\x03 Select a "POKEMON" in the open BOX\n"
		"   with the + Control Pad.\n"
		"\x80\x04 Select “Withdraw” to remove the\n"
		"   "POKEMON" from the BOX and add it to\n"
		"   your party.\n"
		"You may not withdraw a "POKEMON" if you\n"
		"already have six "POKEMON" with you!"
	},
	{ //66, "content_07D"
		"Using “Deposit”",
		"\x80\x03 Select a "POKEMON" in your party with\n"
		"   the + Control Pad.\n"
		"\x80\x04 Select “Deposit.”\n"
		"\x80\x05 Select the box, then press the\n"
		"   A Button to store the "POKEMON".\n"
		"If you have only one "POKEMON" with you,\n"
		"it may not be stored!"
	},
	{ //67, "content_07E"
		"Using “Move”",
		"\x80\x03 Select a "POKEMON" in the open BOX.\n"
		"\x80\x04 Pick up the "POKEMON" by selecting\n"
		"   “Move” and move it anywhere with\n"
		"   the + Control Pad.\n"
		"\x80\x05 Move the "POKEMON" to the BOX name\n"
		"   and press left or right to move it\n"
		"   to another BOX."
	},
	{ //68, "content_07F"
		"Moving items",
		"\x80\x03 Faintly shown "POKEMON" can be made\n"
		"   to hold an item by selecting it and\n"
		"   pressing the A Button.\n"
		"\x80\x04 Clearly shown "POKEMON" can be made\n"
		"   to give the item they are holding to\n"
		"   another "POKEMON", or return the item\n"
		"   to the Bag with the A Button."
	},
	{ //69, "content_080"
		"Using “\x1F\x01's PC”",
		"\x80\x03 Select “\x1F\x01's PC” on the PC.\n"
		"\x80\x04 Select either “Item Storage” or\n"
		"   “Mailbox.”\n"
		"You may store things in your own PC\n"
		"if your Bag is full. You may also\n"
		"withdraw items stored in your PC."
	},
	{ //70, "content_081"
		"Using “Withdraw Item”",
		"\x80\x03 Select “Withdraw Item.”\n"
		"\x80\x04 Select the item to be withdrawn.\n"
		"\x80\x05 The item can be withdrawn and\n"
		"   placed in the Bag's Items pocket.\n"
		"   It may also be directly given to a\n"
		"   "POKEMON" to hold."
	},
	{ //71, "content_082"
		"Using “Deposit Item”",
		"\x80\x03 Select “Deposit Item.”\n"
		"\x80\x04 Select the item in the Bag to be\n"
		"   deposited using the + Control Pad.\n"
		"\x80\x05 If there is more than one \n"
		"   item to be deposited, enter the\n"
		"   quantity with the + Control Pad,\n"
		"   then press the A Button."
	},
	{ //72, "content_083"
		"Using “Mailbox”",
		"When mail is taken from a "POKEMON",\n"
		"it is moved to the Mailbox. If it has\n"
		"no mail, the Mailbox can't be used.\n"
		"\x80\x03 Select “\x1F\x01'S PC” on the PC.\n"
		"\x80\x04 Select “Mailbox” to read mail or\n"
		"   make a "POKEMON" hold mail."
	},
	{ //73, "content_084"
		"Using “"PROFOAK"'S PC”",
		"\x80\x03 Select “"PROFOAK"'s PC” on the PC.\n"
		"\x80\x04 "PROFOAK" will evaluate your\n"
		"   "POKE"Dex.\n"
		"His evaluations should give you hints\n"
		"for catching more "POKEMON"!"
	},
	{ //74, "content_085"
		"Opening the menu",
		"\x80\x03 Press START.\n"
		"\x80\x04 The menu will open on the right.\n"
		"\x80\x05 Depending on the situation, the menu\n"
		"   may feature different headings.\n"
		"The menu will not open in certain\n"
		"situations such as when talking, doing\n"
		"something, battling, etc."
	},
	{ //75, "content_086"
		"Using “Fight”",
		"\x80\x03 Select “Fight.”\n"
		"\x80\x04 Select one of the moves shown,\n"
		"and that move will be used!"
	},
	{ //76, "content_087"
		"Using “"POKEMON"”",
		"\x80\x03 Select “"POKEMON".”\n"
		"\x80\x04 Select the "POKEMON" in your party\n"
		"   that you want to use.\n"
		"\x80\x05 If you have two or more "POKEMON"\n"
		"   with you, they may be switched by\n"
		"   selecting “Shift.” Check "POKEMON"\n"
		"   data by selecting “Summary.”"
	},
	{ //77, "content_088"
		"Using “Shift”",
		"This command switches the "POKEMON" in\n"
		"battle with another one in your party.\n"
		"\x80\x03 Select the "POKEMON" to be sent out.\n"
		"\x80\x04 Select “Shift.”\n"
		"\x80\x05 The selected "POKEMON" will switch\n"
		"   places with the "POKEMON" in battle!"
	},
	{ //78, "content_089"
		"Using “Summary”",
		"\x80\x03 Select “Summary.”\n"
		"\x80\x04 Press left or right on the + Control\n"
		"   Pad to check the information:\n"
		"   “"POKEMON" Info”\n"
		"   “"POKEMON" Skills”\n"
		"   “Known Moves”"
	},
	{ //79, "content_08A"
		"Using “Bag”",
		"\x80\x03 Select “Bag.”\n"
		"\x80\x04 Press left or right on the + Control\n"
		"   Pad to check the data headings:\n"
		"   “Items”\n"
		"   “Key Items”\n"
		"   “"POKE" Balls”\n"
		"   Press up or down to select an item."
	},
	{ //80, "content_08B"
		"Reading the “"POKE"Dex”",
		"\x80\x03 "POKEMON" that you have caught are\n"
		"   identified by a "POKE" Ball mark on\n"
		"   the "POKE"Dex list.\n"
		"\x80\x04 A caught "POKEMON" will provide a\n"
		"   large amount of data.\n"
		"\x80\x05 Select “Area” to display the Town\n"
		"   Map with the "POKEMON"'s habitat(s)."
	},
	{ //81, "content_08C"
		"Using the PC at home",
		"\x80\x03 Go up to the PC at home, then press\n"
		"   the A Button.\n"
		"\x80\x04 The PC will turn on.\n"
		"\x80\x05 Select either “Item Storage” or\n"
		"   “Mailbox.”"
	},
	{ //82, "content_08D"
		"Using the Item Storage System",
		"\x80\x03 Select “Withdraw Item” to withdraw\n"
		"   an item stored on your PC.\n"
		"\x80\x04 Select “Deposit Item” to put \n"
		"   an item from your Bag into your PC."
	},
	{ //83, "content_08E"
		"Using “Withdraw Item”",
		"\x80\x03 Select “Withdraw Item.”\n"
		"\x80\x04 Select the item to be withdrawn.\n"
		"\x80\x05 The item can be withdrawn and\n"
		"   placed in the Bag's Items pocket.\n"
		"   It may also be directly given to a\n"
		"   "POKEMON" to hold."
	},
	{ //84, "content_08F"
		"Using “Deposit Item”",
		"\x80\x03 Select “Deposit Item.”\n"
		"\x80\x04 Select the item in the Bag to be\n"
		"   deposited using the + Control Pad.\n"
		"\x80\x05 If there is nothing in the Bag, this\n"
		"   command can't be used!"
	},
	{ //85, "content_090"
		"Using the Mailbox",
		"When mail is taken from a "POKEMON",\n"
		"it is moved to the Mailbox. If it has\n"
		"no mail, the Mailbox can't be used.\n"
		"\x80\x03 Select mail by name to read it or\n"
		"   make a "POKEMON" hold it."
	},
	{ //86, "content_091"
		"Using “Run”",
		"You may not run from a Trainer\n"
		"battle!\n"
		"\x80\x03 You may run from a wild "POKEMON".\n"
		"\x80\x04 Your chance of escape is improved\n"
		"   if your "POKEMON" in battle is fast."
	},
	{ //87, "content_092"
		"“Register” a key item",
		"You may register a key item for\n"
		"instant use by pressing SELECT!\n"
		"\x80\x03 Open the “Key Items” pocket.\n"
		"\x80\x04 Select the key item, then select\n"
		"   “Register.”"
	},
	{ //88, "content_093"
		"Using “Ball”",
		"\x80\x03 Select to throw the special "POKE"\n"
		"   Ball used only in the Safari ZONE.\n"
		"When wild "POKEMON" appear, throw lots\n"
		"of Safari Balls to catch them!"
	},
	{ //89, "content_094"
		"Using “Bait”",
		"\x80\x03 Select to throw the special food\n"
		"   used only in the Safari Zone.\n"
		"It is "POKEMON" food rolled up into\n"
		"a ball for easy eating. When bait is\n"
		"thrown, the wild "POKEMON" may get\n"
		"attracted by it, and may not flee!"
	},
	{ //90, "content_095"
		"Using “Rock”",
		"\x80\x03 Select to throw a rock lying on\n"
		"   the ground in the Safari Zone.\n"
		"Throwing a rock at a "POKEMON" may \n"
		"make it run away, but it becomes easier\n"
		"to catch!"
	},
	{ //91, "content_096"
		"Using “Hall of Fame”",
		"\x80\x03 Select “Hall of Fame” on the PC.\n"
		"\x80\x04 The "POKEMON" that have entered the\n"
		"   Hall of Fame can be examined."
	},
	{ //92, "content_0C9"
		"HP",
		"HP indicates a "POKEMON"'s vitality.\n"
		"If a "POKEMON"'s HP drops to zero, it\n"
		"faints and is unable to battle.\n"
		"So, the key in battle is to try to\n"
		"reduce the foe's HP to zero.\n"
		"If your "POKEMON" are hurt, restore their\n"
		"HP at a "POKEMON" Center or use items."
	},
	{ //93, "content_0CA"
		"EXP. (EXP. Points)",
		"EXP. Points stands for “Experience\n"
		"Points.” "POKEMON" gain EXP. Points by\n"
		"participating in winning battles.\n"
		"When a "POKEMON" accumulates sufficient\n"
		"EXP. Points, it levels up. The EXP. Bar\n"
		"indicates accumulated EXP. Points.\n"
		"It returns to zero upon leveling up."
	},
	{ //94, "content_0CB"
		"Moves",
		""POKEMON" may learn up to four different\n"
		"moves. There are many kinds of moves\n"
		"including attacks and those with\n"
		"special effects. The kinds of moves\n"
		"that can be learned vary for each\n"
		""POKEMON". Some moves can be learned\n"
		"from items."
	},
	{ //95, "content_0CC"
		"Attack",
		"Attack indicates the power of an\n"
		"offensive move. The higher this stat,\n"
		"the more powerful the move.\n"
		"It is applied for the following move\n"
		"types: Normal, Poison, Ground,\n"
		"Flying, Bug, Fighting, Rock, Ghost,\n"
		"and Steel."
	},
	{ //96, "content_0CD"
		"DEFENSE",
		"DEFENSE indicates the resistance a\n"
		""POKEMON" has against physical attacks.\n"
		"The higher this stat, the less damage\n"
		"sustained from a foe's physical hit."
	},
	{ //97, "content_0CE"
		"SP. ATK",
		"SP. ATK (Special Attack) indicates the\n"
		"power of a special attack move.\n"
		"The higher this stat, the more powerful\n"
		"the special attack move.\n"
		"It is applied for the following move\n"
		"types: Fire, Water, Electric, Grass,\n"
		"Ice, Psychic, Dragon, and Dark."
	},
	{ //98, "content_0CF"
		"SP. DEF",
		"SP. DEF (Special Defense) indicates\n"
		"the resistance a "POKEMON" has against\n"
		"special attacks.\n"
		"The higher this stat, the less damage\n"
		"sustained from a foe's special attack."
	},
	{ //99, "content_0D0"
		"SPEED",
		"SPEED indicates the agility of a\n"
		""POKEMON". If this stat exceeds the foe's\n"
		"in battle, the "POKEMON" can make a move\n"
		"before its slower opponent."
	},
	{ //100, "content_0D1"
		"Lv. (Level)",
		"Lv. (Level) indicates the growth and\n"
		"strength of a "POKEMON".\n"
		"In general, when a "POKEMON" levels up,\n"
		"its stats such as HP, Attack, and\n"
		"DEFENSE rise, making it stronger.\n"
		""POKEMON" may learn a new move upon\n"
		"leveling up."
	},
	{ //101, "content_0D2"
		"TYPE",
		""POKEMON" and moves are classified by\n"
		"type. Every type has advantageous and\n"
		"disadvantageous matchups against\n"
		"other types. For example, like a rock-\n"
		"paper-scissors game, the Water type is\n"
		"strong against the Fire type and weak\n"
		"against the Grass type."
	},
	{ //102, "content_0D3"
		"OT",
		"OT stands for “Original Trainer,”\n"
		"the first Trainer to have caught the\n"
		"selected "POKEMON".\n"
		"Even if the "POKEMON" is traded, the OT\n"
		"name will remain unchanged."
	},
	{ //103, "content_0D4"
		"Item",
		"All "POKEMON" can be made to hold one\n"
		"item each. Some items will be used by\n"
		"the "POKEMON" automatically in certain\n"
		"situations. To make a "POKEMON" hold an\n"
		"item, select the item from the Bag and\n"
		"“GIVE” it to the "POKEMON"."
	},
	{ //104, "content_0D5"
		"ABILITY",
		"All "POKEMON" have a special ABILITY.\n"
		"There are many different kinds of these\n"
		"abilities, some used in battle, some\n"
		"elsewhere. The abilities differ from\n"
		"species to species. Some species may\n"
		"have more than one kind of ability."
	},
	{ //105, "content_0D6"
		"MONEY",
		"Whenever you win a battle against a\n"
		"Trainer, you are given prize money.\n"
		"Save up your prize money so you can\n"
		"enjoy shopping at "POKEMON" Marts!"
	},
	{ //106, "content_0D7"
		"Move TYPE",
		"Moves are also classified by types.\n"
		"If a "POKEMON" of a certain type uses\n"
		"a move of the same type, the move's\n"
		"power is boosted. If the move's type\n"
		"has a matchup advantage against the\n"
		"target, its effectiveness is also\n"
		"boosted."
	},
	{ //107, "content_0D8"
		"NATURE",
		"All "POKEMON" have a personality,\n"
		"or “NATURE.” The "POKEMON"'s\n"
		"nature appears to affect how the\n"
		""POKEMON" will grow upon leveling up."
	},
	{ //108, "content_0D9"
		"ID No.",
		"The ID No. is a special number assigned\n"
		"specifically to you as a Trainer.\n"
		"Together with the OT name, the ID No.\n"
		"is used to precisely identify the\n"
		"Original Trainer.\n"
		"The ID No. does not change even if the\n"
		""POKEMON" is traded."
	},
	{ //109, "content_0DA"
		"PP",
		"PP stands for “Power Points.”\n"
		"It indicates the number of times a\n"
		"certain move can be used in battle.\n"
		"Like HP, PP can be restored by visiting\n"
		"a "POKEMON" Center or using certain\n"
		"items."
	},
	{ //110, "content_0DB"
		"POWER",
		"POWER indicates the strength of an\n"
		"attack. The higher this number, the\n"
		"greater the damage that can be\n"
		"inflicted on the foe!"
	},
	{ //111, "content_0DC"
		"ACCURACY",
		"ACCURACY indicates the probability of\n"
		"the move hitting the foe.\n"
		"The higher this number, the more likely\n"
		"the move will strike the target."
	},
	{ //112, "content_0DD"
		"FNT",
		"FNT stands for “fainted.”\n"
		"A "POKEMON" faints if its HP is reduced\n"
		"to zero. It becomes incapable of taking\n"
		"part in battle.\n"
		"Restore a fainted "POKEMON" at a "POKEMON"\n"
		"Center, or use an item."
	},
	{ //113, "content_0DE"
		"Items",
		"Ordinary items bought at any "POKEMON"\n"
		"Mart are placed in the Items pocket.\n"
		"Items may be used, given to a "POKEMON"\n"
		"to hold, or tossed out as garbage."
	},
	{ //114, "content_0DF"
		"Key Items",
		"Important items that you find or \n"
		"receive from people are placed in the\n"
		"Key Items pocket.\n"
		"Key items may be used, or registered\n"
		"for use instantly with SELECT. Once\n"
		"registered, the item can be used\n"
		"without opening the menu and Bag."
	},
	{ //115, "content_0E0"
		""POKE" Balls",
		""POKE" Balls, which are used for\n"
		"catching wild "POKEMON", are placed in\n"
		"the "POKE" Balls pocket.\n"
		""POKE" Balls may be bought at "POKEMON"\n"
		"Marts. They may be used, given to a\n"
		""POKEMON" to hold, or tossed out as\n"
		"garbage."
	},
	{ //116, "content_0E1"
		""POKE"DEX",
		"This indicates the number of species of\n"
		""POKEMON" you have caught and/or\n"
		"evolved to fill the "POKE"DEX.\n"
		"Try hard to catch all sorts of\n"
		""POKEMON"!"
	},
	{ //117, "content_0E2"
		"PLAY TIME",
		"This is the total amount of time that\n"
		"you have played this game."
	},
	{ //118, "content_0E3"
		"BADGES",
		"The "POKEMON" League BADGES that you\n"
		"have won are registered and shown.\n"
		"Earn BADGES by defeating Gym LeaderS\n"
		"in various cities and towns."
	},
	{ //119, "content_0E4"
		"TEXT SPEED",
		"You can adjust how quickly the text is\n"
		"displayed. Choose one: SLOW, MID,\n"
		"or FAST."
	},
	{ //120, "content_0E5"
		"BATTLE SCENE",
		"You can choose to turn the battle\n"
		"animation ON or OFF."
	},
	{ //121, "content_0E6"
		"BATTLE STYLE",
		"You can choose whether or not a\n"
		"Trainer can switch a "POKEMON" after\n"
		"it has made its foe faint.\n"
		"Set to “Shift” if you would like the\n"
		"chance to switch a "POKEMON" after it\n"
		"has made its foe faint."
	},
	{ //122, "content_0E7"
		"SOUND",
		"You can choose between MONO and\n"
		"STEREO sound output."
	},
	{ //123, "content_0E8"
		"BUTTON MODE",
		"Set to “HELP” to display help messages\n"
		"by pressing the L or R Button.\n"
		"Set to “LR” to enable the switching\n"
		"of the "POKE"DEX pages and Bag pocketS\n"
		"using the L and R Buttons.\n"
		"Set to “L=A” to make the L Button\n"
		"work the same as the A Button."
	},
	{ //124, "content_0E9"
		"FRAME",
		"You may choose the design of the frame\n"
		"around certain menus. Try them out and\n"
		"see what you like."
	},
	{ //125, "content_0EA"
		"Cancel",
		"The settings will be changed to the\n"
		"selections shown in red, and you will\n"
		"return to the menu."
	},
	{ //126, "content_0EB"
		"TM",
		"A TM (Technical Machine) is a device\n"
		"used to teach a move to a "POKEMON".\n"
		"There are many different kinds.\n"
		"Moves can be taught only to those\n"
		""POKEMON" capable of using them.\n"
		"A TM breaks after a single use."
	},
	{ //127, "content_0EC"
		"HM",
		"An HM (Hidden Machine) is a device used\n"
		"to teach a Hidden Move to a "POKEMON".\n"
		"A Hidden Move can be taught only to\n"
		"those "POKEMON" capable of using it.\n"
		"Unlike a TM, an HM can be used over\n"
		"and over. A Hidden Move can be tough\n"
		"for a "POKEMON" to forget."
	},
	{ //128, "content_0ED"
		"HM Move",
		"Hidden Moves are those that are\n"
		"especially important for your\n"
		"adventure. To use such a move outside\n"
		"of battle, open the “"POKEMON"” menu\n"
		"and make the "POKEMON" that knows the\n"
		"move use it. A fainted "POKEMON" may use\n"
		"a Hidden Move outside of battle."
	},
	{ //129, "content_0EE"
		"EVOLUTION",
		"Among "POKEMON", there are some that\n"
		"undergo major changes (evolution) upon\n"
		"growing to certain levels. Evolution\n"
		"causes a "POKEMON" to alter form, change\n"
		"its name, and perhaps change the moves\n"
		"it may learn. Some "POKEMON" evolve\n"
		"due to reasons other than leveling up."
	},
	{ //130, "content_0EF"
		"STATUS PROBLEM",
		"Status problems include:\n"
		"Sleep: Can't use moves.\n"
		"Poison: Causes steady HP loss.\n"
		"Paralysis: May prevent moves.\n"
		"Burn: HP loss and lowers Attack.\n"
		"Freeze: Can't use moves.\n"
		"These can be healed with items, etc."
	},
	{ //131, "content_0F0"
		""POKEMON"",
		""POKEMON" is a name given to describe\n"
		"wondrous creatures that inhabit all\n"
		"corners of this world.\n"
		"People raise "POKEMON" to be their pets,\n"
		"use them for battling, and so on."
	},
	{ //132, "content_0F1"
		"ID No.",
		"The ID No. is a special number assigned\n"
		"specifically to you as a Trainer.\n"
		"Together with the OT name, the ID No.\n"
		"is used to precisely identify the\n"
		"Original Trainer.\n"
		"The ID No. does not change even if the\n"
		""POKEMON" is traded."
	},
	{ //133, "content_0F2"
		"MONEY",
		"Whenever you win a battle against a\n"
		"Trainer, you are given prize money.\n"
		"Save up your prize money so you can\n"
		"enjoy shopping at "POKEMON" Marts!"
	},
	{ //134, "content_0F3"
		"BADGES",
		"This indicates the number of "POKEMON"\n"
		"League BADGES that you have won.\n"
		"Earn BADGES by defeating Gym LeaderS\n"
		"in various cities and towns."
	},
	{ //135, "content_121"
		"The HELP System",
		"The help messages change depending on\n"
		"how much you have progressed in the\n"
		"game. They are designed to support you\n"
		"when you need them. If there is\n"
		"anything that you don't understand,\n"
		"please look up the HELP System!"
	},
	{ //136, "content_122"
		"The game",
		"You become the main character to\n"
		"explore the world of "POKEMON"!\n"
		"By talking to people and solving\n"
		"mysteries, new paths will open to you.\n"
		"Strive for the goal together with your\n"
		"wonderful "POKEMON"!"
	},
	{ //137, "content_123"
		"Wireless Adapter",
		"This game communicates over a wireless\n"
		"link using the Wireless Adapter.\n"
		"Go wireless anywhere, anytime, and\n"
		"with anybody!\n"
		"Try playing with the Wireless Adapter\n"
		"always attached!"
	},
	{ //138, "content_124"
		"Game fundamentals 1",
		"Visit every city and town, travel every\n"
		"road, explore every cave, and face\n"
		"every challenge as you strive to\n"
		"become the greatest Trainer of\n"
		""POKEMON"!"
	},
	{ //139, "content_125"
		"Game fundamentals 2",
		"On your adventure, you will be faced\n"
		"with many obstacles. Every obstacle\n"
		"can be overcome by doing something\n"
		"or by solving mysteries. Some obstacles\n"
		"are affected by something that happens\n"
		"far away."
	},
	{ //140, "content_126"
		"Game fundamentals 3",
		"Some of the obstacles in your way can\n"
		"be removed once your "POKEMON" learn\n"
		"specific moves."
	},
	{ //141, "content_127"
		"What are "POKEMON"?",
		""POKEMON" are wondrous creatures that\n"
		"are shrouded in mystery. You may meet\n"
		"them all over the world\x85in tall\n"
		"grass, caves, the sea, and more.\n"
		"They appear to grow obedient to the\n"
		"Trainers that caught them."
	},
	{ //142, "content_131"
		"Using the Type Matchup List",
		"Depending on the matchup of the\n"
		"move type and the target "POKEMON"'s\n"
		"type, the move's effectiveness varies:\n"
		"\x80\x16: Super effective!\n"
		"\x80\x17: Not very effective\n"
		"*: Not effective at all\n"
		"(No changes for other matchups.)"
	},
	{ //143, "content_132"
		"Own move type: Dark",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Psychic, Ghost\n"
		"   \x80\x17: Fighting, Dark, Steel"
	},
	{ //144, "content_133"
		"Own "POKEMON" type: Dark",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Fighting, Bug\n"
		"   \x80\x17: Ghost, Dark\n"
		"   *: Psychic"
	},
	{ //145, "content_134"
		"Own move type: Rock",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Fire, Ice, Flying, Bug\n"
		"   \x80\x17: Fighting, Ground, Steel"
	},
	{ //146, "content_135"
		"Own "POKEMON" type: Rock",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Water, Grass, Fighting,\n"
		"       Ground, Steel\n"
		"   \x80\x17: Normal, Fire, Poison, Flying"
	},
	{ //147, "content_136"
		"Own move type: Psychic",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Fighting, Poison\n"
		"   \x80\x17: Psychic, Steel\n"
		"   *: Dark"
	},
	{ //148, "content_137"
		"Own "POKEMON" type: Psychic",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Bug, Ghost, Dark\n"
		"   \x80\x17: Fighting, Psychic"
	},
	{ //149, "content_138"
		"Own move type: Fighting",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Normal, Ice, Rock, Dark, Steel\n"
		"   \x80\x17: Poison, Flying, Psychic, Bug\n"
		"   *: Ghost"
	},
	{ //150, "content_139"
		"Own "POKEMON" type: Fighting",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Flying, Psychic\n"
		"   \x80\x17: Bug, Rock, Dark"
	},
	{ //151, "content_13A"
		"Own move type: Grass",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Water, Ground, Rock\n"
		"   \x80\x17: Fire, Grass, Poison, Flying,\n"
		"       Bug, Dragon, Steel"
	},
	{ //152, "content_13B"
		"Own "POKEMON" type: Grass",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Fire, Ice, Poison, Flying, Bug\n"
		"   \x80\x17: Water, Electric, Grass, Ground"
	},
	{ //153, "content_13C"
		"Own move type: Ghost",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Psychic, Ghost\n"
		"   \x80\x17: Dark, Steel\n"
		"   *: Normal"
	},
	{ //154, "content_13D"
		"Own "POKEMON" type: Ghost",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Ghost, Dark\n"
		"   \x80\x17: Poison, Bug\n"
		"   *: Normal, Fighting"
	},
	{ //155, "content_13E"
		"Own move type: Ice",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Grass, Ground, Flying, Dragon\n"
		"   \x80\x17: Fire, Water, Ice, Steel"
	},
	{ //156, "content_13F"
		"Own "POKEMON" type: Ice",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Fire, Fighting, Rock, Steel\n"
		"   \x80\x17: Ice"
	},
	{ //157, "content_140"
		"Own move type: Ground",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Fire, Electric, Poison, Rock,\n"
		"       Steel\n"
		"   \x80\x17: Grass, Bug\n"
		"   *: Flying"
	},
	{ //158, "content_141"
		"Own "POKEMON" type: Ground",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Water, Grass, Ice\n"
		"   \x80\x17: Poison, Rock\n"
		"   *: Electric"
	},
	{ //159, "content_142"
		"Own move type: Electric",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Water, Flying\n"
		"   \x80\x17: Electric, Grass, Dragon\n"
		"   *: Ground"
	},
	{ //160, "content_143"
		"Own "POKEMON" type: Electric",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Ground\n"
		"   \x80\x17: Electric, Flying, Steel"
	},
	{ //161, "content_144"
		"Own move type: Poison",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Grass\n"
		"   \x80\x17: Poison, Ground, Rock, Ghost\n"
		"   *: Steel"
	},
	{ //162, "content_145"
		"Own "POKEMON" type: Poison",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Ground, Psychic\n"
		"   \x80\x17: Grass, Fighting, Poison, Bug"
	},
	{ //163, "content_146"
		"Own move type: Dragon",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Dragon\n"
		"   \x80\x17: Steel"
	},
	{ //164, "content_147"
		"Own "POKEMON" type: Dragon",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Ice, Dragon\n"
		"   \x80\x17: Fire, Water, Electric, Grass"
	},
	{ //165, "content_148"
		"Own move type: Normal",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x17: Rock, Steel\n"
		"   *: Ghost"
	},
	{ //166, "content_149"
		"Own "POKEMON" type: Normal",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Fighting\n"
		"   *: Ghost"
	},
	{ //167, "content_14A"
		"Own move type: Steel",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Ice, Rock\n"
		"   \x80\x17: Fire, Water, Electric, Steel"
	},
	{ //168, "content_14B"
		"Own "POKEMON" type: Steel",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Fire, Fighting, Ground\n"
		"   \x80\x17: Normal, Grass, Ice, Flying,\n"
		"       Psychic, Bug, Rock, Ghost,\n"
		"       Dragon, Dark, Steel\n"
		"   *: Poison"
	},
	{ //169, "content_14C"
		"Own move type: Flying",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Grass, Fighting, Bug\n"
		"   \x80\x17: Electric, Rock, Steel"
	},
	{ //170, "content_14D"
		"Own "POKEMON" type: Flying",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Electric, Ice, Rock\n"
		"   \x80\x17: Grass, Fighting, Bug\n"
		"   *: Ground"
	},
	{ //171, "content_14E"
		"Own move type: Fire",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Grass, Ice, Bug, Steel\n"
		"   \x80\x17: Fire, Water, Rock, Dragon"
	},
	{ //172, "content_14F"
		"Own "POKEMON" type: Fire",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Water, Ground, Rock\n"
		"   \x80\x17: Fire, Grass, Ice, Bug, Steel"
	},
	{ //173, "content_150"
		"Own move type: Water",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Fire, Ground, Rock\n"
		"   \x80\x17: Water, Grass, Dragon"
	},
	{ //174, "content_151"
		"Own "POKEMON" type: Water",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Electric, Grass\n"
		"   \x80\x17: Fire, Water, Ice, Steel"
	},
	{ //175, "content_152"
		"Own move type: Bug",
		"Effect on the opposing "POKEMON":\n"
		"   \x80\x16: Grass, Psychic, Dark\n"
		"   \x80\x17: Fire, Fighting, Poison,\n"
		"       Flying, Ghost, Steel"
	},
	{ //176, "content_153"
		"Own "POKEMON" type: Bug",
		"Effect of foe's move on own "POKEMON":\n"
		"   \x80\x16: Fire, Flying, Rock\n"
		"   \x80\x17: Grass, Fighting, Ground"
	},
};

const aHelpList help_maintopics[] =
{
	{ "About this game", 3, //0
		{
			{ 0, (u32*)&help_content[135] }, //content_121
			{ 0, (u32*)&help_content[136] }, //content_122
			{ 2, 0 }
		}
	},
	{ "About this game", 5, //1
		{
			{ 0, (u32*)&help_content[135] }, //content_121
			{ 0, (u32*)&help_content[136] }, //content_122
			{ 0, (u32*)&help_content[141] }, //content_127
			{ 2, 0 }
		}
	},
	{ "About this game", 8, //2
		{
			{ 0, (u32*)&help_content[135] }, //content_121
			{ 0, (u32*)&help_content[136] }, //content_122
			{ 0, (u32*)&help_content[138] }, //content_124
			{ 0, (u32*)&help_content[139] }, //content_125
			{ 0, (u32*)&help_content[140] }, //content_126
			{ 0, (u32*)&help_content[141] }, //content_127
			{ 2, 0 }
		}
	},
	{ "What should I do in this situation?", 4, //3
		{
			{ 0, (u32*)&help_content[1] }, //content_00E
			{ 0, (u32*)&help_content[2] }, //content_00F
			{ 0, (u32*)&help_content[3] }, //content_010
			{ 2, 0 }
		}
	},
	{ "What does this term mean?", 31, //4
		{
			{ 0, (u32*)&help_content[100] }, //content_0D1
			{ 0, (u32*)&help_content[92] }, //content_0C9
			{ 0, (u32*)&help_content[94] }, //content_0CB
			{ 0, (u32*)&help_content[127] }, //content_0EC
			{ 0, (u32*)&help_content[129] }, //content_0EE
			{ 0, (u32*)&help_content[128] }, //content_0ED
			{ 0, (u32*)&help_content[96] }, //content_0CD
			{ 0, (u32*)&help_content[97] }, //content_0CE
			{ 0, (u32*)&help_content[98] }, //content_0CF
			{ 0, (u32*)&help_content[99] }, //content_0D0
			{ 0, (u32*)&help_content[101] }, //content_0D2
			{ 0, (u32*)&help_content[102] }, //content_0D3
			{ 0, (u32*)&help_content[103] }, //content_0D4
			{ 0, (u32*)&help_content[104] }, //content_0D5
			{ 0, (u32*)&help_content[106] }, //content_0D7
			{ 0, (u32*)&help_content[107] }, //content_0D8
			{ 0, (u32*)&help_content[108] }, //content_0D9
			{ 0, (u32*)&help_content[109] }, //content_0DA
			{ 0, (u32*)&help_content[110] }, //content_0DB
			{ 0, (u32*)&help_content[111] }, //content_0DC
			{ 0, (u32*)&help_content[130] }, //content_0EF
			{ 0, (u32*)&help_content[112] }, //content_0DD
			{ 0, (u32*)&help_content[129] }, //content_0EE
			{ 0, (u32*)&help_content[113] }, //content_0DE
			{ 0, (u32*)&help_content[114] }, //content_0DF
			{ 0, (u32*)&help_content[115] }, //content_0E0
			{ 0, (u32*)&help_content[117] }, //content_0E2
			{ 0, (u32*)&help_content[133] }, //content_0F2
			{ 0, (u32*)&help_content[134] }, //content_0F3
			{ 2, 0 }
		}
	},
	{ "Type Matchup List", 20, //5
		{
			{ 0, (u32*)&help_content[142] }, //content_131
			{ 0, (u32*)&help_content[143] }, //content_132
			{ 0, (u32*)&help_content[144] }, //content_133
			{ 0, (u32*)&help_content[145] }, //content_134
			{ 0, (u32*)&help_content[146] }, //content_135
			{ 0, (u32*)&help_content[147] }, //content_136
			{ 0, (u32*)&help_content[148] }, //content_137
			{ 0, (u32*)&help_content[149] }, //content_138
			{ 0, (u32*)&help_content[150] }, //content_139
			{ 0, (u32*)&help_content[151] }, //content_13A
			{ 0, (u32*)&help_content[152] }, //content_13B
			{ 0, (u32*)&help_content[153] }, //content_13C
			{ 0, (u32*)&help_content[154] }, //content_13D
			{ 0, (u32*)&help_content[155] }, //content_13E
			{ 0, (u32*)&help_content[156] }, //content_13F
			{ 0, (u32*)&help_content[157] }, //content_140
			{ 0, (u32*)&help_content[174] }, //content_151
			{ 0, (u32*)&help_content[175] }, //content_152
			{ 0, (u32*)&help_content[176] }, //content_153
			{ 2, 0 }
		}
	},
};

const aHelpList help_index[] =
{
	{ "", 2,
		{
			{ 1, (u32*)&help_maintopics[0] }, //about1
			{ 2, 0 }
		}
	},
	{ "", 3,
		{
			{ 1, (u32*)&help_maintopics[1] }, //about2
			{ 1, (u32*)&help_maintopics[3] }, //whattodo1
			{ 2, 0 }
		}
	},
	{ "", 4,
		{
			{ 1, (u32*)&help_maintopics[2] }, //about3
			{ 1, (u32*)&help_maintopics[4] }, //terms2
			{ 1, (u32*)&help_maintopics[5] }, //typematchup
			{ 2, 0 }
		}
	},
};

