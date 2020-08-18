class ExpansionMissionConstructor
{
	void GenerateMissionTypes( out map< string, typename > missionMap )
	{
		TTypenameArray missionArrayNames = new TTypenameArray;
		RegisterMissions( missionArrayNames);

		Sort( missionArrayNames, missionArrayNames.Count() );
		
		missionMap = new map< string, typename >;
		
		for(int i = 0; i < missionArrayNames.Count(); i++)
		{
			if ( missionArrayNames[i].IsInherited( ExpansionMissionEventBase ) )
			{
				missionMap.Insert( missionArrayNames[i].ToString(), missionArrayNames[i] );
			}
		}
	}

	void RegisterMissions( out TTypenameArray missions )
	{
		missions.Insert( ExpansionMissionEventAirdrop );
		//missions.Insert( ExpansionMissionEventHorde ); //! Not Ready
		//missions.Insert( ExpansionMissionEventSoldier );
		//missions.Insert( ExpansionMissionEventAI );
		//missions.Insert( ExpansionMissionEventQuest );
	}
}