class ActionPullBody: ActionInteractBase
{
	void ActionPullBody()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override bool IsInstant()
	{
		return true;
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
		EntityAI ntarget = EntityAI.Cast( target.GetObject());

		if(IsInReach(player, target, 0.6))
		{
			player.can_Drag_Body = false;
			return player.can_Drag_Body;
		}

		if(IsInReach(player, target, 2.0))
		{
			if( ntarget && !ntarget.IsAlive())
			{
				player.can_Drag_Body = true;
				return player.can_Drag_Body;
			}
		}
		
		player.can_Drag_Body = false;
		return player.can_Drag_Body;
	}
}