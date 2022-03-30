import sys
import matplotlib.pyplot as plt

lines = sys.argv[1]
intersections = sys.argv[2]

lines = [float(i) for i in lines.split(',')]
intersections = [float(i) for i in intersections.split(',')]

def visualize_intersections(lines,intersections):
    for i in range(0,len(lines),4):
        line_seg_x = [lines[i],lines[i+2]]
        line_seg_y = [lines[i+1],lines[i+3]]
        plt.plot(line_seg_x,line_seg_y,color = 'green',label = 'lines')
        plt.title('Lines and their intersections')
        plt.xlabel('---------->x')
        plt.ylabel('---------->y')
    i = 0
    while(i < len(intersections)):
        intersection_x = [intersections[i]]
        intersection_y = [intersections[i+1]]
        plt.scatter(intersection_x,intersection_y, color = 'red',label = 'intersection points')
        i += 2
visualize_intersections(lines,intersections)
plt.savefig('result.jpg')
