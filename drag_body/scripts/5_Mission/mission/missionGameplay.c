modded class MissionGameplay
{
	void BBP_Move_Body(EntityAI body, vector a)
	{
		GetRPCManager().SendRPC( "drag_body", "BBP_Move_Body_To", new Param2< EntityAI, vector > ( body, a ) );
		body.SetPosition(a);
		//playerPB.BBPsetSize(a); //OFFLINE TESTING 
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

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
		
		//Open workbench UI
		if (GetGame().GetInput().LocalHold("UAAction", true))
		{
			if(player.can_Drag_Body == true)
			{
				if(BBP_getObjectAtCrosshair() != NULL)
				{
					EntityAI DeadBody = EntityAI.Cast(BBP_getObjectAtCrosshair());

					vector player_location = player.GetPosition();
					vector dead_location = DeadBody.GetPosition();
					vector player_Orientation = player.GetOrientation();
					vector dead_Orientation = DeadBody.GetOrientation();

					vector draghere_old = player_location + dead_location;
					vector drag_Orientation = player_Orientation + dead_Orientation;

					drag_Orientation = drag_Orientation * 0.5;
					draghere_old = draghere_old * 0.5;

					for(int ii = 0; ii < 6; ii++)
					{
						drag_Orientation += drag_Orientation;
						drag_Orientation = drag_Orientation * 0.5;
					}

					//half way so it's not under the player

					for(int i = 0; i < 5; i++)
					{
						draghere_old += dead_location;
						draghere_old = draghere_old * 0.5;
					}

					BBP_Move_Body(DeadBody,draghere_old);
					//DeadBody.SetPosition(draghere_old);
					//data.param1.SetPosition(data.param2);
				}
			}
		}
	}
}
