	.file	"g3header.s"
	.text
	.align	2
	.code	16

	.extern PokePicsFront
	.extern PokePicsBack
	.extern PokePicsPalette
	.extern PokePicsShinyPal
	.extern PartyPics
	.extern PartyPal
	.extern PokeNames
	.extern atknames
	.extern BaseStats
	.extern Abilities
	.extern AbilityDescriptions
	.extern items
	.extern attacks
	.extern pokeballs

	.ascii	"openpoke - hot skitty on wailord"
	.int	PokePicsFront
	.int	PokePicsBack
	.int	PokePicsPalette
	.int	PokePicsShinyPal
	.int	PartyPics
	.int	PartyPal
	.int	PokeNames
	.int	atknames
	.int	BaseStats
	.int	Abilities
	.int	AbilityDescriptions
	.int	items
	.int	attacks
	.int	pokeballs
	
	

