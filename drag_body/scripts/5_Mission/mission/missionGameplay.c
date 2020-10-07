modded class MissionGameplay
{
	// UIs
	ref WB_Spawn_Item m_WB_Spawn_Item;
	ref BuildingMenu m_BuildingMenu;
	ref BuildingMenu2 m_BuildingMenu2;
	ref BuildingMenuBBP m_BuildingMenuBBP;

	void MissionGameplay()
    {
		m_BuildingMenu = NULL;
		m_BuildingMenu2 = NULL;
		m_BuildingMenuBBP = NULL;
		m_WB_Spawn_Item = new WB_Spawn_Item();
	}

	void BBPsetSize(PlayerBase playerPB, int a)
	{
		GetRPCManager().SendRPC( "BaseBuildingPlus", "BBP_SYNC_SIZES", new Param2< PlayerBase, int > ( playerPB, a ) ); 
		//playerPB.BBPsetSize(a); //OFFLINE TESTING 
	}

	override void OnUpdate(float timeslice)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;

		if(player)
		{
			if(player.GetHumanInventory())
			{
				if(player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}

		WBUIMenu sample_menu = WBUIMenu.Cast(m_UIManager.FindMenu(MENU_WBUI_MENU));

        // Input Declarations
        UAInput EscapeKeyInput = GetUApi().GetInputByName("UAUIBack");

		//TODO CLEAN UP MESS =D
		if (GetGame().GetInput().LocalPress("UACycleSize", true))
		{
			if(player.GetHologramLocal())
			{
				//600x300
				if(BBP_CYCLE_SIZE == 1 || BBP_CYCLE_SIZE == 4 || BBP_CYCLE_SIZE == 5 || BBP_CYCLE_SIZE == 6 || BBP_CYCLE_SIZE == 7)
				{
					//GetRPCManager().SendRPC("BaseBuildingPlus", "BBP_SYNC_SIZES", new Param1< int >( BBP_CYCLE_SIZE ));
					BBPsetSize(player,2);
					BBP_CYCLE_SIZE = 2;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}

				//300x300
				else if(BBP_CYCLE_SIZE == 2 || BBP_CYCLE_SIZE == 8 || BBP_CYCLE_SIZE == 9 || BBP_CYCLE_SIZE == 10 || BBP_CYCLE_SIZE == 11)
				{
					//GetRPCManager().SendRPC("BaseBuildingPlus", "BBP_SYNC_SIZES", new Param1< int >( BBP_CYCLE_SIZE ));
					BBPsetSize(player,3);
					BBP_CYCLE_SIZE = 3;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}

				//150x150
				else if(BBP_CYCLE_SIZE == 3 || BBP_CYCLE_SIZE == 12 || BBP_CYCLE_SIZE == 13 || BBP_CYCLE_SIZE == 14 || BBP_CYCLE_SIZE == 15)
				{
					//GetRPCManager().SendRPC("BaseBuildingPlus", "BBP_SYNC_SIZES", new Param1< int >( BBP_CYCLE_SIZE ));
					BBPsetSize(player,1);
					BBP_CYCLE_SIZE = 1;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
			}
		}
		
		//Cycle parts
		if (GetGame().GetInput().LocalPress("UACyclePart", true))
		{
			if(player.GetHologramLocal())
			{
				//600x600
				if(BBP_CYCLE_SIZE == 1 || BBP_CYCLE_SIZE == 4)
				{
					BBPsetSize(player,5);
					BBP_CYCLE_SIZE = 5;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 5)
				{
					BBPsetSize(player,6);
					BBP_CYCLE_SIZE = 6;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 6)
				{
					BBPsetSize(player,7);
					BBP_CYCLE_SIZE = 7;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 7)
				{
					BBPsetSize(player,4);
					BBP_CYCLE_SIZE = 4;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				//300x300
				else if(BBP_CYCLE_SIZE == 2 || BBP_CYCLE_SIZE == 8)
				{
					BBPsetSize(player,9);
					BBP_CYCLE_SIZE = 9;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 9)
				{
					BBPsetSize(player,10);
					BBP_CYCLE_SIZE = 10;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 10)
				{
					BBPsetSize(player,11);
					BBP_CYCLE_SIZE = 11;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 11)
				{
					BBPsetSize(player,8);
					BBP_CYCLE_SIZE = 8;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				//150x150
				else if(BBP_CYCLE_SIZE == 3 || BBP_CYCLE_SIZE == 12)
				{
					BBPsetSize(player,13);
					BBP_CYCLE_SIZE = 13;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 13)
				{
					BBPsetSize(player,14);
					BBP_CYCLE_SIZE = 14;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 14)
				{
					BBPsetSize(player,15);
					BBP_CYCLE_SIZE = 15;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				else if(BBP_CYCLE_SIZE == 15)
				{
					BBPsetSize(player,12);
					BBP_CYCLE_SIZE = 12;
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
			}
		}

        if (!m_UIManager.IsDialogVisible())
        {
            if (sample_menu && EscapeKeyInput.LocalPress())
            {
                CloseAllMenus();
                GetUIManager().HideScriptedMenu(sample_menu);
                PlayerControlEnable(false);
                ShowHUD(true);
            }
        }

		//open Snapping UI
		if (GetGame().GetInput().LocalPress("UABuildSnapUI", true))
		{
			if (iteminhands)
			{
				if (iteminhands.canSnap())
				{	
					if (!m_BuildingMenu && !m_BuildingMenu2 && !m_BuildingMenuBBP)
					{
						m_BuildingMenu = new BuildingMenu;
						GetGame().GetUIManager().ShowScriptedMenu( m_BuildingMenu, NULL );
					}
				}
				
				if (iteminhands.canSnapFloor())
				{	
					if (!m_BuildingMenu && !m_BuildingMenu2 && !m_BuildingMenuBBP)
					{
						m_BuildingMenu2 = new BuildingMenu2;
						GetGame().GetUIManager().ShowScriptedMenu( m_BuildingMenu2, NULL );
					}
				}
				
				//BBP3 New Snapping UI
				if (iteminhands.canSnapBBP() || iteminhands.canSnapFloorBBP())
				{	
					if (!m_BuildingMenu && !m_BuildingMenu2 && !m_BuildingMenuBBP)
					{
						m_BuildingMenuBBP = new BuildingMenuBBP;
						GetGame().GetUIManager().ShowScriptedMenu( m_BuildingMenuBBP, NULL );
					}
				}
			}
		}
		
		if (GetGame().GetInput().LocalPress("UASnapLook", true)) //snap by looking
		{
			if (iteminhands)
			{
				if (iteminhands.canSnapBBP() || iteminhands.canSnapFloorBBP())
				{
					//ENABLE WITH MANUAL ROTATION
					if(AUTO_BBP_SNAPPING_OBJECT && !auto_snapper && snappingEnabled && snappingEnabled_By_Looking)
					{
						auto_snapper = true;

						//HERE UI DISPLAY ROTATION ENABLED
					}

					//ENABLE WITH AUTO ROTATION
					else if(!snappingEnabled_By_Looking && !snappingEnabled)
					{
						snappingEnabled_By_Looking = true;
						snappingEnabled = true;

						//HERE UI DISPLAY ROTATION DISABLED
					}

					//DISABLE
					else
					{
						snappingEnabled_By_Looking = false;
						auto_snapper = false;
						snappingEnabled = false;
						AUTO_BBP_SNAPPING_OBJECT = NULL;
					}
				}
			}
        }

		if(snappingEnabled_By_Looking)
		{
			if (iteminhands)
			{
				if (iteminhands.canSnapBBP() || iteminhands.canSnapFloorBBP())
				{
					if(BBP_getObjectAtCrosshair())
					{
						if(BBP_getObjectAtCrosshair().IsInherited(BBP_BASE))
						{
							BBP_SelectObject();
						}
					}
				}
			}
		}

		if(snappingEnabled_By_Looking && !auto_snapper)
		{
			if (GetGame().GetInput().LocalPress("UAPrevSnap", true)) //prev snap point
			{
				if (iteminhands)
				{
					if (iteminhands.canSnap150())
					{
						if (iteminhands.canSnapBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevWall_150();
							}
							if (BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlat_150();
							}
						}
						if (iteminhands.canSnapFloorBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlatWall_150();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlatFloor_150();
							}
						}
					}
					if (iteminhands.canSnap300())
					{
						if (iteminhands.canSnapBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevWall_300();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlat_300();
							}
						}
						if (iteminhands.canSnapFloorBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlatWall_300();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlatFloor_300();
							}
						}
					}
					if (iteminhands.canSnap600())
					{
						if (iteminhands.canSnapBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevWall_600();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlat_600();
							}
						}
						if (iteminhands.canSnapFloorBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlatWall_600();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlatFloor_600();
							}
						}
					}
				}
			}

			if (GetGame().GetInput().LocalPress("UANextSnap", true)) //next snap point		
			{
				if (iteminhands)
				{
					if (iteminhands.canSnap150())
					{
						if (iteminhands.canSnapBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextWall_150();
							}
							if (BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlat_150();
							}
						}
						if (iteminhands.canSnapFloorBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlatWall_150();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlatFloor_150();
							}
						}
					}
					if (iteminhands.canSnap300())
					{
						if (iteminhands.canSnapBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextWall_300();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlat_300();
							}
						}
						if (iteminhands.canSnapFloorBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlatWall_300();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlatFloor_300();
							}
						}
					}
					if (iteminhands.canSnap600())
					{
						if (iteminhands.canSnapBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextWall_600();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlat_600();
							}
						}
						if (iteminhands.canSnapFloorBBP())
						{
							if (!BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlatWall_600();
							}
							if (BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlatFloor_600();
							}
						}
					}
				}
			}
		}
		
		//toggle Display of BBP Inventory
		if (GetGame().GetInput().LocalPress("UABBPInv", true))
		{
			BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
			if (bbp_config)
			{
				bool BBPInventoryToggle = bbp_config.g_BBPInventoryToggle;
			}
			if ( BBPInventoryToggle )
			{
				if (BBP_Hide)
				{
					BBP_Hide = false;
				}
				else if (!BBP_Hide)
				{
					BBP_Hide = true;
				}
			}
		}
		super.OnUpdate(timeslice);
	}

	// HUD Control
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    void ShowHUD(bool state)
    {
        GetHud().Show(state);
    }

	// Work around until I figire out why UAUIMenu doesn't work in Update event
	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);

		if (key == KeyCode.KC_ESCAPE)
		{
			if(m_BuildingMenu)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_BuildingMenu);
				delete m_BuildingMenu;
			}

			if(m_BuildingMenu2)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_BuildingMenu2);
				delete m_BuildingMenu2;
			}

			if(m_BuildingMenuBBP)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_BuildingMenuBBP);
				delete m_BuildingMenuBBP;
			}
		}
	}
}
