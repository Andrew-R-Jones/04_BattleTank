// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation(); // component location of the track

	 // get the owner->Tank_BP, get the owner's root component->Tank (Scene Component), 
	//			then cast that from a static mesh to a primitive component
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); 
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}