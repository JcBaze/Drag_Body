class Drag_Body_To_Location
{
	// Set Body Position (MP support)
	static void SetBodyPosition(EntityAI body, vector position)
	{
		if ( GetGame().IsServer() )
		{

			//body.SetPosition( position );
		}
		else
		{
			ref Param3<float, float, float> params = new Param3<float, float, float>(position[0], position[1], position[2]);
			body.RPCSingleParam(DBMRPCs.RPC_DRAG_BODY, params, true);
		}
	}

    static void OnRPC(EntityAI body, int rpc_type, ParamsReadContext ctx)
	{
		if ( !GetGame().IsDebug() )
		{
			return;
		}
	
		if ( rpc_type == DBMRPCs.RPC_DRAG_BODY )
		{
			OnRPCSetBodyPosition(body, ctx);
		}
	}
	
	static protected void OnRPCSetBodyPosition(EntityAI body, ParamsReadContext ctx)
	{
		ref Param3<float, float, float> p = new Param3<float, float, float>(0, 0, 0);
		if (ctx.Read(p))
		{
			vector v = "0 0 0";
			v[0] = p.param1;
			v[1] = p.param2;
			v[2] = p.param3;
			SetBodyPosition(body, v);
		}
	}
}