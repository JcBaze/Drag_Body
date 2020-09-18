class ActionPullBodyCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.1;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
}

class ActionPullBody: ActionContinuousBase
{
	private EntityAI body_EAI;

	void ActionPullBody()
	{
		m_CallbackClass = ActionPullBodyCB;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
	}

	bool HasProgress()
	{
		return false;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "Drag";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase ntarget = PlayerBase.Cast( target.GetObject());

		if(IsInReach(player, target, 0.6))
		{
			return false;
		}

		if(IsInReach(player, target, 2.0))
		{
			if( ntarget && !ntarget.IsAlive())
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		//PlayerBase m_Dead_Body = PlayerBase.Cast(action_data.m_Target.GetObject());

		PluginDragBody DragBodyTo = PluginDragBody.Cast( GetPlugin( PluginDragBody ));

		PlayerBase m_Dead_Body = action_data.m_Target.GetObject();

		vector player_location = action_data.m_Player.GetPosition();
		vector dead_location = action_data.m_Target.GetObject().GetPosition();
		vector player_Orientation = action_data.m_Player.GetOrientation();
		vector dead_Orientation = action_data.m_Target.GetObject().GetOrientation();

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

		for(int i = 0; i < 2; i++)
		{
			draghere_old += dead_location;
			draghere_old = draghere_old * 0.5;
		}

		//dBodyActive(body_EAI, ActiveState.ACTIVE);
		//dBodyActive(body_EAI, ActiveState.ACTIVE);
		
		//Print
		
		

		//body_EAI.Synchronize();
		// vector draghere4 = draghere_old * 0.5;
		// draghere4 += dead_location;
		// vector draghere5 = draghere4 * 0.5;
		// draghere5 += dead_location;
		// vector draghere6 = draghere5 * 0.5;
		// draghere6 += dead_location;
		// vector draghere7 = draghere6 * 0.5;

		//action_data.m_Target.GetObject().SetPosition(draghere_old);
		//action_data.m_Target.GetObject().SetOrientation(drag_Orientation);
		
		//m_Dead_Body.Drag_Update(m_Dead_Body,draghere_old);

		//Drag_Body_To_Location.SetBodyPosition(m_Dead_Body,draghere_old);


		Drag_Body_To_Location.SetBodyPosition(m_Dead_Body,draghere_old);
		//DragBodyTo.Drag_Body_To(m_Dead_Body,draghere_old);

		//GetGame().RPCSingleParam( m_Dead_Body, 1783, new Param1<vector>(draghere_old), true, NULL );



		//g_Game.ObjectDelete(m_Dead_Body);
		//m_Dead_Body.SetWorldPosition(draghere_old);
		//GetGame().ObjectModelToWorld(m_Dead_Body,draghere_old);
	}
	
	
}