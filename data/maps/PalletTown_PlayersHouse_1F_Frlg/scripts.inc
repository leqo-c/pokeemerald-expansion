PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_PlayersHouse_1F_OnFrame
	.byte 0

PalletTown_PlayersHouse_1F_OnFrame:
	map_script_2 VAR_TEMP_0, 0, PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayerOnEntry
	.2byte 0

PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayerOnEntry::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_MET_MOM_IN_PLAYERS_HOUSE_1F, PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayerDone
	goto PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayer
	end

PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayer::
	lockall
	goto_if_set FLAG_MET_MOM_IN_PLAYERS_HOUSE_1F, PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayerDone
	setflag FLAG_MET_MOM_IN_PLAYERS_HOUSE_1F
	playse SE_PIN
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, PalletTown_PlayersHouse_1F_Movement_MomApproachPlayer
	waitmovement 0
	msgbox PalletTown_PlayersHouse_1F_Text_MomApproachPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, PalletTown_PlayersHouse_1F_Movement_MomReturn
	waitmovement 0
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_MomApproachPlayerDone::
	releaseall
	end

PalletTown_PlayersHouse_1F_Movement_MomApproachPlayer::
	walk_up
	walk_up
	walk_right
	step_end

PalletTown_PlayersHouse_1F_Movement_MomReturn::
	walk_left
	walk_down
	walk_down
	face_left
	step_end

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_MomApproachPlayer::
	.string "Vagabondo brinzellone!\n"
	.string "Ma ti sembra l'ora di svegliarsi?\l"
	.string "Massimo è passato a lasciare un pacco,\p"
	.string "passa dalle poste per piacere.$"

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
	.string "MOM: …Right.\n"
	.string "All boys leave home someday.\l"
	.string "It said so on TV.\p"
	.string "Oh, yes. PROF. OAK, next door, was\n"
	.string "looking for you.$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
	.string "MOM: …Right.\n"
	.string "All girls dream of traveling.\l"
	.string "It said so on TV.\p"
	.string "Oh, yes. PROF. OAK, next door, was\n"
	.string "looking for you.$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "MOM: {PLAYER}!\n"
	.string "You should take a quick rest.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
	.string "MOM: Oh, good! You and your\n"
	.string "POKéMON are looking great.\l"
	.string "Take care now!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
	.string "There's a movie on TV.\n"
	.string "Four boys are walking on railroad\l"
	.string "tracks.\p"
	.string "…I better go, too.$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
	.string "There's a movie on TV.\n"
	.string "A girl with her hair in pigtails is\l"
	.string "walking up a brick road.\p"
	.string "…I better go, too.$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
	.string "Oops, wrong side…$"
