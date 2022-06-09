#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sys/time.h>

#define DEFAULT_K 5
#define DEFAULT_NITERS 20

using namespace std;

struct point_t {
  double x;
  double y;
};

double get_time() {
  struct timeval tv;
  gettimeofday(&tv, (struct timezone *)0);
  return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}

void read_points(std::string filename, point_t *p, int n) {
  std::ifstream infile{filename};
  double x, y;
  int i = 0;
  while (infile >> x >> y) {
    if (i >= n) {
      printf(
          "WARNING: more points in input file '%s' than read: stopping after "
          "%d lines\n",
          filename.c_str(), i);
      return;
    }
    p[i].x = x;
    p[i].y = y;
    i++;
  }
}

void write_result(std::string filename, int niters, point_t *result, int k) {
  std::ofstream outfile{filename};
  for (int iter = 0; iter < niters + 1; ++iter) {
    for (int i = 0; i < k; ++i) {
      outfile << iter << ' ' << result[iter * k + i].x << ' '
              << result[iter * k + i].y << '\n';
    }
  }
}

void init_centroids(point_t *centroids, int k) {
  for (int i = 0; i < k; ++i) {
    centroids[i].x = rand() % 100;
    centroids[i].y = rand() % 100;
  }
}

// TODO: Task 1.2
// Implement the k-means algorithm
void k_means(int niters, point_t *points, point_t *centroids, int *assignment,
             point_t *result, int n, int k) {
    
     /*
     niters: pre-defined number of iteration
     *points: array that contains the datapoints in structure point_t
     centroids: array that contains the initialized centroids in strusture point_t
     assignment: array that should contain the assigned centroid to each data point.
     result: array that contain the result of each iteration, i.e. each element of k times point_t
     contains the averaged point of the centorid.
     */
    
    printf("\n running k-means! \n");
    double smallest_dist, cur_dist;
    int *centroid_num = static_cast<int *>(malloc(k * sizeof(int)));
    point_t *sum_points = static_cast<point_t *>(malloc(k * sizeof(point_t)));
    
    
    for(int i = 0; i < k; i++){
        
        result[i].x = centroids[i].x;
        result[i].y = centroids[i].y;
        
    }
    
    //start the loop
    for(int i = 0; i < niters; i++){
        
        // iterate all the datapoints; get each datapoint the closest centroid; assign to the assignment array
        for(int j = 0; j < n; j++){
            
            // initialize the maximum value of a double-parameter
            smallest_dist = DBL_MAX;
            
            // iterate the centroids
            for(int h = 0; h < k; h++){
                
                // get the distance
                cur_dist = (points[j].x - centroids[h].x)*(points[j].x - centroids[h].x) + (points[j].y - centroids[h].y)*(points[j].y - centroids[h].y);
                
                if(cur_dist <= smallest_dist){
                    
                    smallest_dist = cur_dist;
                    assignment[j] = h;
                }
            } // assign the current datapoint to h_th centroid
            //centroid_num[assignment[j]] += 1;
        }
        
        // now assigning and computing the distance for each point is done
        
        // now try to summarize the results
        /* need:
         1. mean coordinate information of each centroid
         2. number of datapoints for each centroid
         */
        // initialize centroids with zero
        for(int j = 0; j < k; j++){
            
            sum_points[j].x = 0;
            sum_points[j].y = 0;
            centroid_num[j] = 0;
            
        }
        // update centroids
        for(int j = 0; j < n; j++){
            
            centroid_num[assignment[j]]++;
            sum_points[assignment[j]].x += points[j].x;
            sum_points[assignment[j]].y += points[j].y;
            
        }
        
        for(int j = 0; j < k; j++){
            
            centroids[j].x = sum_points[j].x /centroid_num[j];
            centroids[j].y = sum_points[j].y /centroid_num[j];
            
        }
        
        
        // update result
        for(int j = 0; j < k; j++){
            
            result[j + (i+1) * k].x = centroids[j].x;
            result[j + (i+1) * k].y = centroids[j].y;
            
        }
        
    }
    
}


int main(int argc, const char *argv[]) {
  // Handle input arguments
  if (argc < 3 || argc > 5) {
    printf("Usage: %s <input file> <num points> <num centroids> <num iters>\n",
           argv[0]);
    return EXIT_FAILURE;
  }
  const char *input_file = argv[1];
  const int n = atoi(argv[2]);
  const int k = (argc > 3 ? atoi(argv[3]) : DEFAULT_K);
  const int niters = (argc > 4 ? atoi(argv[4]) : DEFAULT_NITERS);

  // Allocate and initialize data
  point_t *points = static_cast<point_t *>(malloc(n * sizeof(point_t)));
  point_t *centroids = static_cast<point_t *>(malloc(k * sizeof(point_t)));
  int *assignment = static_cast<int *>(malloc(n * sizeof(int)));
  srand(1234);
  read_points(input_file, points, n);
  init_centroids(centroids, k);

  // TODO: Task 1.3
  // For verifying the results by visualization, result contains space for the
  // position of the centroids of the initial configuration and at every
  // iteration of the algorithm. In the end, it is written to a file.
  // For debugging purposes, the array is set to values outside the domain.
  point_t *result =
      static_cast<point_t *>(malloc((niters + 1) * k * sizeof(point_t)));
  for (int i = 0; i < (niters + 1) * k; ++i) {
    result[i].x = -1.0;
    result[i].y = -1.0;
  }
  // TODO: Task 1.3
  // Write the initial position of the centroids to result

  printf("Executing k-means clustering with %d iterations, %d points, and %d "
         "centroids...\n",
         niters, n, k);

  double runtime = get_time();
  k_means(niters, points, centroids, assignment, result, n, k);
  runtime = get_time() - runtime;

  printf("Time Elapsed: %f s\n", runtime);

  // TODO: Task 1.3
  // Verify the results by visualization (by using "make vis-small" or "make vis-large")
  write_result("result.out", niters, result, k);

  free(assignment);
  free(centroids);
  free(points);
  free(result);

  return EXIT_SUCCESS;
}
