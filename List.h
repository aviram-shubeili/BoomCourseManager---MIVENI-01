#ifndef LIST_H
#define LIST_H
#include "Node.h"

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
     * Description: will disconnect the lecture node from the list
     * note: will not remove the views node even if it is the last node 
     * may throw this exceptions:
     *
     *
     */
    void disconnectLecture(std::shared_ptr<Node> next, std::shared_ptr<Node> prev);
    /**
     * Description: will remove views node if need to
     * gets the prev to the removed lecture node
     * may throw this exceptions:
     *
     *
     */
    void removeViews(std::shared_ptr<Node> next, std::shared_ptr<Node> prev);
            /**
     * Description: will add lacture node to given views node
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> addLectureToViews(std::shared_ptr<Node> node_views_ptr, std::shared_ptr<Node> node_lecture_ptr);
public:
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    List();
        /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    ~List();
    /**
     * Description: will remove the lecture node from the list and will reconnect / remove needed nodes
     * 
     * may throw this exceptions:
     *
     *
     */
    void removeLecture(std::shared_ptr<Node> node_lecture_ptr);
    /**
     * Description:will start new lecture in 0
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> addLecture(int new_course_id, int new_class_id);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    std::shared_ptr<Node> moveLecture(std::shared_ptr<Node> node_lecture_ptr, int time);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    int getLectureViews(std::shared_ptr<Node> node_lecture_ptr);
    /**
     * Description:
     *
     * may throw this exceptions:
     *
     *
     */
    void getMostViewd(int numOfClasses, int* courses, int* classes);

};
#endif
