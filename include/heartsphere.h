#pragma once
#ifndef HEARTSPHERE_H
#define HEARTSPHERE_H

#include "hittable.h"
#include "vec3.h"
#include <limits>

class heartsphere : public hittable {
public:
	heartsphere(point3 _center) : center(_center) {};

	bool hit(const ray& r, double t_min, double t_max, _Out_ hit_record& rec) const override {

		auto delta = 0.001;
		auto max = 20;

		//F = (x ^ 2 + (9 / 4) * y ^ 2 + z ^ 2 - 1) ^ 3 - (x ^ 2) * (z ^ 3) - (9 / 80) * y ^ 2 * z ^ 3
		auto x_0 = r.origin().x() - center.x();
		auto y_0 = r.origin().y() - center.y();
		auto z_0 = r.origin().z() - center.z();
		
		auto x_r = r.direction().x();
		auto y_r = r.direction().y();
		auto z_r = r.direction().z();
		
		for (auto t = t_min; t < max; t += delta) {
			auto x_t = x_0 + x_r * t;
			auto z_t = y_0 + y_r * t;
			auto y_t = -(z_0 + z_r * t);

			auto A = x_t * x_t + (9.0 / 4.0) * y_t * y_t + z_t * z_t - 1.0;
			auto B = x_t * x_t * z_t * z_t * z_t;
			auto C = (9.0 / 80.0) * y_t * y_t * z_t * z_t * z_t;

			auto F = A * A * A - B - C;
			if (abs(F) <= delta) {
				auto t_0 = (x_t * x_t);
				auto t_1 = (y_t * y_t);
				auto t_2 = (z_t * z_t * z_t);
				auto t_22 = t_2 / z_t;
				auto t_3 = (((t_0 - 1.0) + t_22) + ((9.0 * t_1) / 4.0));
				
	
				// translate normal vector to word coordinates
				// x_w = x; y_w = -z; z_w = y
				auto g_x = (((6.0 * x_t) * (t_3 * t_3)) - (2.0 * (x_t * t_2)));
				auto g_z = -(((54.0 * (y_t * (t_3 * t_3))) / 4.0) - ((2.0 * ((9.0 * y_t) * t_2)) / 80.0));
				auto g_y = ((((6.0 * z_t) * (t_3 * t_3)) - (3.0 * (t_22 * t_0))) - ((3.0 * ((9.0 * t_22) * t_1)) / 80.0));
				
				rec.t = t;
				rec.p = r.at(rec.t);
				vec3 outward_normal = unit_vector(vec3(g_x, g_y, g_z)); //determine the normal at geometry
				rec.set_face_normal(r, outward_normal);
				return true;
			}
		}

		return false;
	}

private:
	point3 center;
};

#endif // !HEARTSPHERE_H
