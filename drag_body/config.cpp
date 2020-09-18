class CfgMods
{
	class drag_body
	{
		dir="drag_body";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="drag_body";
		credits="";
		author="Henny";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
        class defs
        {
			class gameScriptModule
            {
                files[] = {"drag_body/Scripts/3_Game"};
			};
            class worldScriptModule
            {
                files[] = {"drag_body/Scripts/4_World"};
			};
			class missionScriptModule
			{
				files[] = {"drag_body/Scripts/5_Mission"};
			};
		};
	};
};
class CfgPatches
{
	class drag_body
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
		};
	};
};