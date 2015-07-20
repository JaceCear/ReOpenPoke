/*
 * GAME OPTIONS
 * -------------
 * Switches
 * --------
 * DEBUG
 *    Enables extra items in the options screen.
 *    Can cause savegame incompatibilities.
 * WITH_SHIRTCOLORS
 *    Enables the shirt color extension
 * DODUO_MAKES_SENSE
 *    Alters the base stats to make Doduo and
 *    Dodrio Normal/Normal type instead of
 *    Normal/Flying, since they are ostrich-like
 *    flightless birds.
 * CUSTOM_RIVAL_NAME
 *    If enabled, asks for a rival name.
 *    If not, uses the first name from the
 *    opposite list.
 * BATTLE_DS_SPECIALS
 *    If enabled, uses 4th generation rules
 *    to determine if a move is special.
 *    3rd generation rule: type is Fire or
 *    higher. 4th generation rule: move
 *    requires touching the opponent.
 *
 * Metrics
 * --------
 * PLACENAMEDELAY
 *    How long the place name box stays
 *    on screen.
 *    Default: 50
 * TEXTWRITEMULTIPLIER
 *    Determines highest possible text
 *    speed. In other words, "how fast
 *    is 'fast'?"
 *    Default: 2
 * DEXFADESPEED
 *    How quickly the Pokédex switches
 *    between pages
 *    Default: 2
 * NUMFRAMES
 *    Number of window frames available
 *    to choose from.
 *    Default: 14
 * WALKSPEED
 *    Delay between steps when walking.
 *    Default: 2
 * RUNSPEED
 *    Delay between steps when running.
 *    Default: 1
 * BIKESPEED
 *    Delay between steps when riding a
 *    bicycle.
 *    Default: 0
 * STATUS_CARDFLIPSPEED
 *    How fast the cards animate in the
 *    Pokémon status screen
 *    Default: 32
 *
 * Names
 * ------
 * POKEMON
 *    The term used to describe the mons.
 *    Default: "Pokémon"
 * POKEMONU
 *    The same as POKEMON, but uppercase.
 *    Default: "POKéMON"
 * POKE
 *    The common prefix, like with "Poké
 *    Ball", "Pokédex"...
 *    Default: "Poké"
 * OAKNAME
 *    The short name for the game's
 *    authority figure.
 *    Default: "Oak"
 * PROFOAK
 *    The full title for the game's
 *    authority figure.
 *    Default: "Prof. Oak"
 * BILLNAME
 *    The short name for the box
 *    system operator/designer,
 *    the "someone".
 *    Default: "Bill"
 *
 * Misc
 * -----
 * INTROMON
 *    Which species should appear in
 *    the game's introduction?
 *    Default: pkNidoranGirl
 * SHINY_MAGIC
 *    Final check value for shininess.
 *    8 gives the common 2/65025 ratio.
 *    Default: 8
 */

// Enable Agb support ?
#define NDEBUG

// Switches
#define DEBUG
#define WITH_SHIRTCOLORS
#define DODUO_MAKES_SENSE
#define CUSTOM_RIVAL_NAME
//#define BATTLE_DS_SPECIALS

// Metrics
#define PLACENAMEDELAY			50
#define TEXTWRITEMULTIPLIER		 2
#define DEXFADESPEED			 2
#define NUMFRAMES				14
#define WALKSPEED				 2
#define RUNSPEED				 1
#define BIKESPEED				 0
#define STATUS_CARDFLIPSPEED	32

//------------------------
// System-wide names
//------------------------
#define POKEMON		"Pokémon"
#define POKEMONU	"POKéMON"
#define POKE			"Poké"
#define OAKNAME		"Apple"//"Maple"
#define PROFOAK		"Prof. Apple"
#define BILLNAME	"Joshua"

#define INTROMON		pkRayquaza
#define SHINY_MAGIC		8
