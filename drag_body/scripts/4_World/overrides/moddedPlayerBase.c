modded class PlayerBase
{
	bool can_Drag_Body = false;

  	override void SetActions() 
	{
		super.SetActions();
		
		AddAction(ActionPullBody);
		//AddAction(ActionPullBodyUncon);
	}
}
