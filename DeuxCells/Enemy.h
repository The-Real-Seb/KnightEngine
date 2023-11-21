#pragma once
#include <KnightEngine/AComponent.h>
#include <KnightEngine/Entity.h>
#include <KnightEngine/CSpriteRenderer.h>
#include <KnightEngine/CRigidbody.h>
#include <KnightEngine/CBoxCollider.h>
#include <KnightEngine/CCollider.h>
#include <KnightEngine/Application.h>

class Enemy : public KE::Entity
{
protected:
	KE::Application* appInstance;
	KE::CRigidbody* rb;
	KE::CSpriteRenderer* sprite;
	KE::CBoxCollider* collider;	

public:
	Enemy();
};

