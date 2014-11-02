#ifndef MATH_VECTOR3_H_
#define MATH_VECTOR3_H_

class v3
{
public:
	v3() {}
	v3( float _x, float _y, float _z ) : x( _x ), y( _y ), z( _z ) {}


	v3 operator+( const v3 & v ) const
	{
		return v3( x + v.x, y + v.y, z + v.z );
	}

	v3 operator-( const v3 & v ) const
	{
		return v3( x - v.x, y - v.y, z - v.z );
	}

	v3 operator+() const
	{
		return *this;
	}

	v3 operator-() const
	{
		return v3( -x, -y, -z );
	}

	v3 operator*( float s ) const
	{
		return v3( x * s, y * s, z * s );
	}

	inline friend v3 operator*( float s, const v3 & v )
	{
		return v3( v.x * s, v.y * s, v.z * s );
	}

	v3 operator/( float s ) const
	{
		float r( 1.0f / s );
		return v3( x * r, y * r, z * r );
	}

	const v3 & operator+=( const v3 & rhs )
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	const v3 & operator*=( float s )
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}

	void Normalise()
	{
		float	len_sq( LengthSq() );
		if(len_sq > 0.0f)
		{
			float r( 1.0f / sqrtf( len_sq ) );
			x *= r;
			y *= r;
			z *= r;
		}
	}

	float Length() const
	{
		return sqrtf( (x*x)+(y*y)+(z*z) );
	}

	float LengthSq() const
	{
		return (x*x)+(y*y)+(z*z);
	}

	float MinComponent() const
	{
		if(x < y && x < z)
		{
			return x;
		}
		else if(y < z)
		{
			return y;
		}
		else
		{
			return z;
		}
	}

	float Dot( const v3 & rhs ) const
	{
		return (x*rhs.x) + (y*rhs.y) + (z*rhs.z);
	}

	float x, y, z;
};

#endif // MATH_VECTOR3_H_
