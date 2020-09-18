modded class PlayerBase
{
	bool Drag_key_Held = false;

//checks has press BUTTON
	bool canDrag()
	{
		return Drag_key_Held;
	}

	void setAction_pull_t()
	{
		Drag_key_Held = true;
	}

	void setAction_pull_f()
	{
		Drag_key_Held = false;
	}


  	override void SetActions() 
	{
		super.SetActions();
		
		AddAction(ActionPullBody);
		//AddAction(ActionPullBodyUncon);
	}
}
