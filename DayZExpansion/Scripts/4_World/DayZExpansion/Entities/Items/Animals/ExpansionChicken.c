/**
 * ExpansionChicken.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		ExpansionChicken
 * @brief		
 **/
class ExpansionChicken extends Inventory_Base
{
	protected string m_TypeChicken;

	protected Animal_GallusGallusDomesticus m_Chicken;

	protected vector m_ThrowImpulse;
	protected bool m_IsThrowing;

	// ------------------------------------------------------------
	// Constructor
	// ------------------------------------------------------------
	void ExpansionChicken()
	{
	}

	// ------------------------------------------------------------
	// Destructor
	// ------------------------------------------------------------
	void ~ExpansionChicken()
	{
	}

	string GetTypeChicken()
	{
		return m_TypeChicken;
	}

	Animal_GallusGallusDomesticus GetChicken()
	{
		return m_Chicken;
	}

	void CreateChicken()
	{
		if ( m_TypeChicken && !m_Chicken )
		{
			m_Chicken = Animal_GallusGallusDomesticus.Cast( GetGame().CreateObject( m_TypeChicken, Vector( 0, 0, 0 ), false, false ) );

			dBodySetInteractionLayer( m_Chicken, PhxInteractionLayers.AI_NO_COLLISION );

			SetLocalSpace();
		}
	}

	void SetChicken( Object chicken )
	{
		m_TypeChicken = chicken.GetType();

		CreateChicken();
	}

	void SetLocalSpace()
	{
		if ( m_Chicken )
		{
			m_Chicken.SetPosition( "0 0 0" );
			m_Chicken.SetOrientation( "0 0 0" );

			AddChild( m_Chicken, -1 );
			m_Chicken.Update();
			Update();
		}
	}

	void SetWorldSpace()
	{
		if ( m_Chicken )
		{
			SetWorldSpaceAt( GetPosition() );
		}
	}

	void SetWorldSpaceAt( vector positon )
	{
		if ( m_Chicken )
		{
			m_Chicken.SetPosition( positon );
			m_Chicken.SetOrientation( "0 0 0" );

			RemoveChild( m_Chicken );
			m_Chicken.Update();
			Update();

			m_Chicken.InitAIAgent( GetGame().GetWorld().GetAIWorld().CreateGroup("DZdomesticGroupBeh") );

			dBodySetInteractionLayer( m_Chicken, PhxInteractionLayers.AI );
		}
	}

	void SetThrowForce( vector force )
	{
		// the physics engine runs at 40hz, an impulse is applied in a singular frame where as a force is applied over a second
		m_ThrowImpulse = force * 40.0;
		m_IsThrowing = true;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave( ctx );
		
		ctx.Write( m_TypeChicken );
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		if ( Expansion_Assert_False( ctx.Read( m_TypeChicken ), "[" + this + "] Failed reading m_TypeChicken" ) )
			return false;

		return true;
	}

	override void AfterStoreLoad()
	{
		CreateChicken();
	}

	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner )
	{
		super.OnItemLocationChanged( old_owner, new_owner );

		if ( IsMissionHost() )
		{
			if ( new_owner == NULL )
			{
				Human man = Human.Cast( old_owner );
				ExpansionBreader breader = ExpansionBreader.Cast( old_owner );
				
				if ( m_Chicken )
				{
					if ( man )
					{
						SetWorldSpace();
					}
					else if ( breader )
					{
						SetWorldSpaceAt( breader.GetPosition() + Vector(0, 0, 0.75) );
					}

					if ( m_IsThrowing )
					{
						dBodyApplyImpulse( m_Chicken, m_ThrowImpulse );
					}

					m_Chicken = NULL;
				}

				if ( man )
				{
					man.LocalDestroyEntityInHands();
				}
			} else if ( old_owner != NULL )
			{
				CreateChicken();
			}
		}
	}
}