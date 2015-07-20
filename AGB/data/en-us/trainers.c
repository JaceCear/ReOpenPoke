#include "../../openpoke.h"

const aTrainerMonster testTrainer[] =
{{50,10,pkMagneton,{1,2,3,4,},10},{50,10,pkMagnemite,{},0}};

const aTrainer Trainers[] =
{
	{
		ttBreeder, 0, tpBreederA,
		"Brown",
		{ 0,0, 0,0 },
		0,
		0x1,
		1,
		(aTrainerMonster*)testTrainer,
	},
};
