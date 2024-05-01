//#include "rtweekend.h"
//
//#include "hittable.h"
//#include "hittable_list.h"
//
//#include "sphere.h"
//#include "heartsphere.h"
//
//#define STB_IMAGE_WRITE_IMPLEMENTATION
////#define STBIW_WINDOWS_UTF8
//#include "stb_image_write.h"
//
////#include "tomsolver.hpp"
//
//
//color ray_color(const ray &r, const hittable& world)
//{
//	hit_record rec;
//    if (world.hit(r, 0, infinity, rec)) {
//		return 0.5 * (rec.normal + color(1, 1, 1));
//	}
//
//	vec3 unit_direction = unit_vector(r.direction());
//	auto a = 0.5 * (unit_direction.y() + 1.0);							// resize t to [0,1]
//	return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0); // lerp, linear interpolation
//}
//
//int main() {
//
//    // Image
//    auto aspect_ratio = 16.0 / 9.0;
//    int image_width = 1920;
//
//
//    // Calculate the image height, and ensure that it's at least 1.
//    int image_height = static_cast<int>(image_width / aspect_ratio);
//    image_height = (image_height < 1) ? 1 : image_height;
//    char* img = (char*)malloc(sizeof(char) * image_width * image_width * 3);
//    std::string name = "image.png";
//
//    // World
//    hittable_list world;
//
//    world.add(make_shared<heartsphere>(point3(0,0,-2)));
//    //world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));
//
//    // Camera
//
//    auto focal_length = 1.0;
//    auto viewport_height = 2.0;
//    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
//    auto camera_center = point3(0, 0, 0);
//
//    // Calculate the vectors across the horizontal and down the vertical viewport edges.
//    auto viewport_u = vec3(viewport_width, 0, 0);
//    auto viewport_v = vec3(0, -viewport_height, 0);
//
//    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
//    auto pixel_delta_u = viewport_u / image_width;
//    auto pixel_delta_v = viewport_v / image_height;
//
//    // Calculate the location of the upper left pixel.
//    auto viewport_upper_left = camera_center
//        - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
//    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
//
//    // Render
//
//    std::cout << name << std::endl << image_width << " " << image_height << std::endl;
//
//    for (int j = 0; j < image_height; ++j) {
//        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
//        for (int i = 0; i < image_width; ++i) {
//            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
//            auto ray_direction = pixel_center - camera_center;
//            
//            ray r(camera_center, ray_direction);
//            color pixel_color = ray_color(r, world); 
//
//			write_color(i, j, image_width, img, pixel_color);
//		}
//	}
//
//	//stbi_flip_vertically_on_write(true); // lower-left as uv-rigin, line scan
//	stbi_write_png(name.c_str(), image_width, image_height, 3, img, 0);
//	std::cerr << "\nDone.              \n";
//    
//
//    //Config::Get().nonlinearMethod = NonlinearMethod::LM;
//
//    //std::setlocale(LC_ALL, ".UTF-8");
//    //try{
//    //SymVec f = {
//    //    "(x^2+(9/4)*y^2+z^2-1)^3-(x^2)*(z^3)-(9/80)*y^2*z^3"_f,
//    //    "x-0.55*t"_f,
//    //    "y-t"_f,
//    //    "z-t"_f
//    //};
//
//    //Config::Get().initialValue = 0.01;
//    //VarsTable ans = Solve(f);
//    //// 打印出ans
//    //std::cout << ans << std::endl;
//
//    //// 单独获取变量的值
//    //std::cout << "t = " << ans["t"] << std::endl;
//    //std::cout << "y = " << ans["y"] << std::endl;
//    //system("pause");
//    //}catch (const std::exception& e) {
//    //std::cerr << e.what() << std::endl;
//    //}
//    //system("pause");
//
//    return 0;
//}
// 
//第三题
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//const int MAXN = 1e5 + 5;
//vector<int> tree[MAXN];
//map<pair<int,int>,int> mem;
//int colors[MAXN];
//int answer = 0;
//
//bool dfs(int node, int parent) {
//    bool has_red = colors[node] == 1;
//    bool has_black = colors[node] == 0;
//    for (int child : tree[node]) {
//        if (child == parent) {
//            continue;
//        }
//        if (mem[{child, node}] == 1) {
//            has_red = true;
//        } else if (mem[{child, node}] == 2) {
//			has_black = true;
//        } else {
//            if (dfs(child, node)) {
//                mem[{child, node}] = 1;
//                has_red = true;
//            }
//            else {
//                mem[{child, node}] = 2;
//                has_black = true;
//            }
//        }
//    }
//    if (has_red && has_black) {
//        answer++;
//    }
//
//    return has_red; 
//}
//
//int main() {
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//
//    for (int i = 0; i < n; ++i) {
//        colors[i + 1] = (s[i] == 'R') ? 1 : 0;
//    }
//
//    for (int i = 1; i < n; ++i) {
//        int u, v;
//        cin >> u >> v;
//        tree[u].push_back(v);
//        tree[v].push_back(u);
//    }
//
//    dfs(1, -1);
//
//    cout << answer << endl;
//
//    return 0;
//}

