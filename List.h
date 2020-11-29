#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <assert.h>
#include <iostream>

/**
 * Description:
 *
 *
 *
 *
 */
class List {
private:
    std::shared_ptr<Node> head;//points to 0 views node
    std::shared_ptr<Node> max;//points to the max views node
    /**
     * Description: will add lecture to the wated node
     * may throw this exceptions:
     */
    static void addLectureToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id);
    /**
     * Description: will remove the node from the list
     * may throw this exceptions:
     */
    static void removeNode(std::shared_ptr<Node> node_ptr);
public:
    /**
     * Description:
     * may throw this exceptions:
     */
    List();
    /**
     * Description:
     * may throw this exceptions:
     */
    ~List();
    /**
     * Description: will remove the lecture from the node (from the course tree)
     * may throw this exceptions:
     */
    static void removeLectureFromNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id);
    /**
     * Description: will add views to wanted leture in node
     * may throw this exceptions:
     */
    void AddViewsToNode(std::shared_ptr<Node> node_ptr, int classes_id, int course_id, int time);
    /**
     * Description: returns the mosted viewed courses
     *note: will not throw errors! you need to check if legal before
     * may throw this exceptions:
     */
    void getMostViewd(int numOfClasses, int* courses, int* classes);
    /**
     * Description: returen the current views of specific lecture
     * may throw this exceptions:
     */
    int getLectureViews(std::shared_ptr<Node> node_lecture_ptr);
    /**
     * Description: will remove the course from the node - will remove node if it is empty
     * may throw this exceptions:
     */
    static void removeCourseFromNode(std::shared_ptr<Node> node_ptr, int course_id);

};
#endif
