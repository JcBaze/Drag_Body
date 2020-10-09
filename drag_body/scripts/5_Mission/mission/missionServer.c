modded class MissionServer
{
    void MissionServer()
    {
        GetRPCManager().AddRPC( "drag_body", "BBP_Move_Body_To", this, SingleplayerExecutionType.Both );
    }

    void BBP_Move_Body_To( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
    {
        // Data passed in by RPC
        Param2< EntityAI, vector > data;
        if ( !ctx.Read( data ) ) return;


        data.param1.SetPosition(data.param2);
        
		//data.param1.SetOrientation(data.param2);

    }
}