class PluginDragBody extends PluginBase
{
	static PluginDragBody GetInstance()
	{
		return PluginDragBody.Cast( GetPlugin( PluginDragBody ) );
	}
	
	//! Teleport player at position
	void Drag_Body_To(EntityAI body, vector position)
	{
		Drag_Body_To_Location.SetBodyPosition(body, position);
	}
	
	void OnRPC(EntityAI body, int rpc_type, ParamsReadContext ctx)
	{
		Drag_Body_To_Location.OnRPC(body, rpc_type, ctx);
	}
}
