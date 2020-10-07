modded class MissionServer
{
    void MissionServer()
    {
        BBPConfig config = BBPGlobals.Get();
        GetDayZGame().setBBPGlobals(config);
        GetRPCManager().AddRPC( "BaseBuildingPlus", "BBP_SYNC_SIZES", this, SingleplayerExecutionType.Both );
    }

    void BBP_SYNC_SIZES( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
    {
        // Data passed in by RPC
        Param2< PlayerBase, int > data;
        if ( !ctx.Read( data ) ) return;

        //PlayerBase.Cast( data.param1 ).BBPsetSize(data.param2);
        // Check that the sender is the PlayerBase that has been passed by RPC (to prevent RPC crossover)
        if ( PlayerBase.Cast(data.param1).GetIdentity().GetId() == sender.GetId() )
        {
            PlayerBase.Cast( data.param1 ).BBPsetSize(data.param2);
        }
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);

        auto configParams = new Param1<BBPConfig>(GetDayZGame().getBBPGlobals());
        GetGame().RPCSingleParam(player, BBPRPC.CHECKBBPCONFIG, configParams, true, identity);
    }
	
	override void OnInit()
	{
		super.OnInit();
        PlaceCementMixers();
	}

    void PlaceCementMixers()
    {
        BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
        ref array<ref CementMixerLocations> CementMixerLoc = bbp_config.g_BBPCementMixerLocations;

		foreach (CementMixerLocations CM : CementMixerLoc )
		{
            vector position = CM.position;
            vector orientation = CM.orientation;
            Object a = GetGame().CreateObject("BBP_Cement_Mixer", position, false);
            a.SetPosition( position );
            a.SetOrientation( orientation );		
		}
    }
}
