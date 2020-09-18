class ActionPullBodyUnconCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.1;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
}

class ActionPullBodyUncon: ActionContinuousBase
{
	EntityAI m_Uncon_Body;

	void ActionPullBodyUncon()
	{
		m_CallbackClass = ActionPullBodyUnconCB;
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
			if( ntarget && ntarget.IsAlive() && ntarget.IsUnconscious())
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase m_Uncon_Body = PlayerBase.Cast(action_data.m_Target.GetObject())

		vector player_location = action_data.m_Player.GetPosition();
		vector uncon_location = action_data.m_Target.GetObject().GetPosition();
		vector player_Orientation = action_data.m_Player.GetOrientation();
		vector uncon_Orientation = action_data.m_Target.GetObject().GetOrientation();

		vector draghere_old = player_location + uncon_location;
		vector drag_Orientation = player_Orientation + uncon_Orientation;

		drag_Orientation = drag_Orientation * 0.5;
		draghere_old = draghere_old * 0.5;

		for(int ii = 0; ii < 6; ii++)
		{
			drag_Orientation += drag_Orientation;
			drag_Orientation = drag_Orientation * 0.5;
		}

		//half way so it's not under the player

		for(int i = 0; i < 2 ; i++)
		{
			draghere_old += uncon_location;
			draghere_old = draghere_old * 0.5;
		}
		// vector draghere4 = draghere_old * 0.5;
		// draghere4 += uncon_location;
		// vector draghere5 = draghere4 * 0.5;
		// draghere5 += uncon_location;
		// vector draghere6 = draghere5 * 0.5;
		// draghere6 += uncon_location;
		// vector draghere7 = draghere6 * 0.5;

		m_Uncon_Body.SetPosition(draghere_old);
		m_Uncon_Body.SetOrientation(drag_Orientation);
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		PlayerBase m_Uncon_Body = PlayerBase.Cast(action_data.m_Target.GetObject())

		vector player_location = action_data.m_Player.GetPosition();
		vector uncon_location = action_data.m_Target.GetObject().GetPosition();
		vector player_Orientation = action_data.m_Player.GetOrientation();
		vector uncon_Orientation = action_data.m_Target.GetObject().GetOrientation();

		vector draghere_old = player_location + uncon_location;
		vector drag_Orientation = player_Orientation + uncon_Orientation;

		drag_Orientation = drag_Orientation * 0.5;
		draghere_old = draghere_old * 0.5;

		for(int ii = 0; ii < 6; ii++)
		{
			drag_Orientation += drag_Orientation;
			drag_Orientation = drag_Orientation * 0.5;
		}

		//half way so it's not under the player

		for(int i = 0; i < 2 ; i++)
		{
			draghere_old += uncon_location;
			draghere_old = draghere_old * 0.5;
		}
		// vector draghere4 = draghere_old * 0.5;
		// draghere4 += uncon_location;
		// vector draghere5 = draghere4 * 0.5;
		// draghere5 += uncon_location;
		// vector draghere6 = draghere5 * 0.5;
		// draghere6 += uncon_location;
		// vector draghere7 = draghere6 * 0.5;

		m_Uncon_Body.SetPosition(draghere_old);
		m_Uncon_Body.SetOrientation(drag_Orientation);
	}
}