	class Slot_uh1hdoor_1_1
	{
		name = "uh1hdoor_1_1";
		displayName = "UH1H Door";
		descriptionShort = "";
		selection = "uh1hdoor_1_1";
		ghostIcon = "doorfront";
	};
	class Slot_uh1hdoor_1_2
	{
		name = "uh1hdoor_1_2";
		displayName = "UH1H Door";
		descriptionShort = "";
		selection = "uh1hdoor_1_2";
		ghostIcon = "doorfront";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class ExpansionWreck;
	class SimulationModule;
	class Axles;
	class Suspension;
	class Front;
	class Rear;
	class AnimationSources;
	class Crew;
	class Driver;
	class CoDriver;
	class ExpansionHelicopterScript;
	class GUIInventoryAttachmentsProps;
	class Body;
	class DamageSystem;
	class DamageZones;
	class GlobalHealth;
	class HatchbackWheel;
	class HatchbackDoors_Driver;
	class ExpansionUh1hDoor_1_1: HatchbackDoors_Driver
	{
		scope = 2;
		displayName = "$STR_EXPANSION_VEHICLE_UH1H_DOOR_LEFT";
		descriptionShort = "$STR_EXPANSION_VEHICLE_UH1H_DOOR_LEFT_DESC";
		model = "\DayZExpansion\Vehicles\Air\Uh1h\proxy\uh1hdoor_1_1.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "uh1hdoor_1_1";
		rotationFlags = 8;
		physLayer = "item_large";
	};
	class ExpansionUh1hDoor_1_2: ExpansionUh1hDoor_1_1
	{
		scope = 2;
		displayName = "$STR_EXPANSION_VEHICLE_UH1H_DOOR_RIGHT";
		descriptionShort = "$STR_EXPANSION_VEHICLE_UH1H_DOOR_RIGHT_DESC";
		model = "\DayZExpansion\Vehicles\Air\Uh1h\proxy\uh1hdoor_1_2.p3d";
		inventorySlot = "uh1hdoor_1_2";
	};
	class ExpansionUh1hWreck: ExpansionWreck
	{
		scope = 2;
		displayname = "$STR_EXPANSION_VEHICLE_UH1H";
		model = "\DayZExpansion\Vehicles\Air\Uh1h\Uh1hWreck.p3d";
		class Cargo
		{
			itemsCargoSize[] = {10,50};
		};
	};
	class ExpansionUh1h: ExpansionHelicopterScript
	{
		scope = 2;
		displayname = "$STR_EXPANSION_VEHICLE_UH1H";
		model = "\DayZExpansion\Vehicles\Air\Uh1h\uh1h.p3d";
		vehicleClass = "Expansion_Helicopter";
		fuelCapacity = 119;
		fuelConsumption = 99;
		attachments[] = {"Reflector_1_1","ExpansionHelicopterBattery","ExpansionIgniterPlug","ExpansionHydraulicHoses","uh1hdoor_1_1","uh1hdoor_1_2"};
		doors[] = {"uh1hdoor_1_1","uh1hdoor_1_2"};
		applySkinsTo[] = {"ExpansionUh1hDoor_1_1","ExpansionUh1hDoor_1_2"};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"dayzexpansion\vehicles\air\uh1h\data\uh1d_co.paa","dayzexpansion\vehicles\air\uh1h\data\uh1d_in_co.paa"};
		hiddenSelectionsMaterials[] = {"dayzexpansion\vehicles\air\uh1h\data\uh1d.rvmat","dayzexpansion\vehicles\air\uh1h\data\uh1d_in.rvmat"};
		defaultSkin = "Green";
		class Cargo
		{
			itemsCargoSize[] = {10,50};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class AnimationSources
		{
			class rotor
			{
				source = "user";
				animPeriod = 0.025;
				initPhase = 0;
			};
			class rearrotor
			{
				source = "user";
				animPeriod = 0.025;
				initPhase = 0;
			};
			class hiderotor
			{
				source = "user";
				animPeriod = 0.0009999999;
				initPhase = 0;
			};
			class hiderotorblur
			{
				source = "user";
				animPeriod = 0.0009999999;
				initPhase = 0;
			};
			class cyclicForward
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
			class cyclicAside
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
			class door_pilot
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class door_copilot
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class uh1hdoor_1_1
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
			class uh1hdoor_1_2
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
		class Crew: Crew
		{
			class Driver: Driver
			{
				actionSel = "seat_driver";
				proxyPos = "crewDriver";
				getInPos = "pos Codriver";
				getInDir = "pos Codriver dir";
			};
			class CoDriver: CoDriver
			{
				actionSel = "seat_codriver";
				proxyPos = "crewCoDriver";
				getInPos = "pos Driver";
				getInDir = "pos Driver dir";
			};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_cargo1";
				getInDir = "pos_cargo1_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_cargo1";
				getInDir = "pos_cargo1_dir";
			};
			class Cargo3
			{
				actionSel = "seat_cargo3";
				proxyPos = "crewCargo3";
				getInPos = "pos_cargo1";
				getInDir = "pos_cargo1_dir";
			};
			class Cargo4
			{
				actionSel = "seat_cargo4";
				proxyPos = "crewCargo4";
				getInPos = "pos_cargo2";
				getInDir = "pos_cargo2_dir";
			};
		};
		class SimulationModule: SimulationModule
		{
			class Axles: Axles
			{
				class Front: Front
				{
					class Suspension: Suspension
					{
						swayBar = 1;
						stiffness = 1;
						compression = 1;
						damping = 1;
						travelMaxUp = 0;
						travelMaxDown = 0;
					};
				};
				class Rear: Rear
				{
					class Suspension: Suspension
					{
						swayBar = 1;
						stiffness = 1;
						compression = 1;
						damping = 1;
						travelMaxUp = 0;
						travelMaxDown = 0;
					};
				};
			};
		};
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.1;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"Expansion_Uh1h_Engine_Ext_SoundSet","Expansion_Uh1h_Rotor_Ext_SoundSet"};
			soundSetsInt[] = {"Expansion_Uh1h_Engine_Int_SoundSet","Expansion_Uh1h_Rotor_Int_SoundSet"};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"ExpansionHelicopterBattery","ExpansionIgniterPlug","ExpansionHydraulicHoses"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1","uh1hdoor_1_1","uh1hdoor_1_2"};
			};
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 7500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class ExpansionSpraycanBase;
	class ExpansionSpraycanGreen: ExpansionSpraycanBase
	{
		scope = 2;
		displayName = "$STR_EXPANSION_SPRAYCAN_Green_NAME";
		descriptionShort = "$STR_EXPANSION_SPRAYCAN_Green_DESC";
		hiddenSelectionsTextures[] = {"DZ\gear\consumables\data\spraycan_green_co.paa"};
		skinName = "Green";
	};
	class ExpansionUh1h_Green: ExpansionUh1h
	{
		skinBase = "ExpansionUh1h";
		skinName = "Green";
	};
	class ExpansionUh1hDoor_1_1_Green: ExpansionUh1hDoor_1_1
	{
		skinBase = "ExpansionUh1hDoor_1_1";
		skinName = "Green";
	};
	class ExpansionUh1hDoor_1_2_Green: ExpansionUh1hDoor_1_2
	{
		skinBase = "ExpansionUh1hDoor_1_2";
		skinName = "Green";
	};
	class ExpansionSpraycanCivilian: ExpansionSpraycanBase
	{
		scope = 2;
		displayName = "$STR_EXPANSION_SPRAYCAN_Civilian_NAME";
		descriptionShort = "$STR_EXPANSION_SPRAYCAN_Civilian_DESC";
		hiddenSelectionsTextures[] = {"DZ\gear\consumables\data\spraycan_black_co.paa"};
		skinName = "Civilian";
	};
	class ExpansionUh1h_Civilian: ExpansionUh1h
	{
		skinBase = "ExpansionUh1h";
		skinName = "Civilian";
	};
	class ExpansionUh1hDoor_1_1_Civilian: ExpansionUh1hDoor_1_1
	{
		skinBase = "ExpansionUh1hDoor_1_1";
		skinName = "Civilian";
	};
	class ExpansionUh1hDoor_1_2_Civilian: ExpansionUh1hDoor_1_2
	{
		skinBase = "ExpansionUh1hDoor_1_2";
		skinName = "Civilian";
	};
	class ExpansionSpraycanMedical: ExpansionSpraycanBase
	{
		scope = 2;
		displayName = "$STR_EXPANSION_SPRAYCAN_Medical_NAME";
		descriptionShort = "$STR_EXPANSION_SPRAYCAN_Medical_DESC";
		hiddenSelectionsTextures[] = {"DZ\gear\consumables\data\spraycan_black_co.paa"};
		skinName = "Medical";
	};
	class ExpansionUh1h_Medical: ExpansionUh1h
	{
		skinBase = "ExpansionUh1h";
		skinName = "Medical";
	};
	class ExpansionUh1hDoor_1_1_Medical: ExpansionUh1hDoor_1_1
	{
		skinBase = "ExpansionUh1hDoor_1_1";
		skinName = "Medical";
	};
	class ExpansionUh1hDoor_1_2_Medical: ExpansionUh1hDoor_1_2
	{
		skinBase = "ExpansionUh1hDoor_1_2";
		skinName = "Medical";
	};
	class ExpansionSpraycanUber: ExpansionSpraycanBase
	{
		scope = 2;
		displayName = "$STR_EXPANSION_SPRAYCAN_Uber_NAME";
		descriptionShort = "$STR_EXPANSION_SPRAYCAN_Uber_DESC";
		hiddenSelectionsTextures[] = {"DZ\gear\consumables\data\spraycan_black_co.paa"};
		skinName = "Uber";
	};
	class ExpansionUh1h_Uber: ExpansionUh1h
	{
		skinBase = "ExpansionUh1h";
		skinName = "Uber";
	};
	class ExpansionUh1hDoor_1_1_Uber: ExpansionUh1hDoor_1_1
	{
		skinBase = "ExpansionUh1hDoor_1_1";
		skinName = "Uber";
	};
	class ExpansionUh1hDoor_1_2_Uber: ExpansionUh1hDoor_1_2
	{
		skinBase = "ExpansionUh1hDoor_1_2";
		skinName = "Uber";
	};
	class ExpansionSpraycanResistance: ExpansionSpraycanBase
	{
		scope = 2;
		displayName = "$STR_EXPANSION_SPRAYCAN_Resistance_NAME";
		descriptionShort = "$STR_EXPANSION_SPRAYCAN_Resistance_DESC";
		hiddenSelectionsTextures[] = {"DZ\gear\consumables\data\spraycan_black_co.paa"};
		skinName = "Resistance";
	};
	class ExpansionUh1h_Resistance: ExpansionUh1h
	{
		skinBase = "ExpansionUh1h";
		skinName = "Resistance";
	};
	class ExpansionUh1hDoor_1_1_Resistance: ExpansionUh1hDoor_1_1
	{
		skinBase = "ExpansionUh1hDoor_1_1";
		skinName = "Resistance";
	};
	class ExpansionUh1hDoor_1_2_Resistance: ExpansionUh1hDoor_1_2
	{
		skinBase = "ExpansionUh1hDoor_1_2";
		skinName = "Resistance";
	};
};
class CfgNonAIVehicles
{
	class ProxyVehiclePart;
	class Proxyuh1hdoor_1_1: ProxyVehiclePart
	{
		model = "\DayZExpansion\Vehicles\Air\Uh1h\proxy\uh1hdoor_1_1.p3d";
		inventorySlot = "uh1hdoor_1_1";
	};
	class Proxyuh1hdoor_1_2: ProxyVehiclePart
	{
		model = "\DayZExpansion\Vehicles\Air\Uh1h\proxy\uh1hdoor_1_2.p3d";
		inventorySlot = "uh1hdoor_1_2";
	};
};
