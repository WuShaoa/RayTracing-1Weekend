#ifndef HITTABLE_H
#define HITTABLE_H

class hit_record {
public:
	point3 p; // hit point
	vec3 normal; // normal vector
	double t; // hit time of the ray
	bool front_face; // whether the ray hits the front face of the object

	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		// Sets the hit record normal vector
		// Note: the parameter `outward_normal` is assumed to be unit vector

		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable {
public:
	virtual ~hittable() = default;

	virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, _Out_ hit_record& rec) const = 0;
};

#endif // !HITTABLE_H