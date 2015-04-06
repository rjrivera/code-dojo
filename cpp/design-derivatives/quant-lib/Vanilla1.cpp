#include "Vanilla1.h"

VanillaOption::VanillaOptino(PayOff& ThePayOff_,
			double Expiry_)
		: ThePayOff(ThePayOff_), Expiry(Expiry)
{

}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption:OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}
