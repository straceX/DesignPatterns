#pragma once

namespace Toolkit
{
	//First implementation of Math class
	struct MathsV1
	{
  	static auto divide(const double lhs, const double rhs) -> double;
  	//...
	};

	//Some reason we need to new implementation of Math class
	//But some functions' signatures are changed
	struct MathsV2 final
	{
  	static auto divide(const double lhs, const double rhs) -> double;
  	//...
	};

	//...
	//The MathsV2 needs some adaptation before the client code can use it.
	//...

	//The Adapter class makes the new Maths V2 class's interface compatible with the legacy codes
	struct Adapter
	{
  	static auto divide(const double lhs, const double rhs) -> double;
  	//...
	};
}

