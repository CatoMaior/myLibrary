/**
 * @file types.h
 * @author Pietro Firpo (pietro.firpo@pm.me)
 * @brief Collection of useful types
 */

#ifndef SEEN_TYPES
#define SEEN_TYPES

/**
 * @brief Alias for char, just to avoid confusion with 8 bit numbers and ASCII characters
 */
typedef char byte;

/**
 * @brief Used to specify type of argument passed in functions that require a type specifier
 * @details Supported specifiers: `"%c"` (char), `"%i"` (int), `"%f"` (float), `"%lf"` (double), `"%p"` (pointer)
 * @note Some functions may not support some identifiers or may support additional identifiers. In those cases refer to that function documentation
 */
typedef char *spec_t;

/**
 * @brief Alias for char *, used when an array of char is actually used as a string
 */
typedef char *string;

/**
 * @brief ::ArrayList type
 * @note All the parameters in this structure must be intended as read-only. Manually modifying them can cause unknown and unwanted behavior
 */
typedef struct {
    /**
     * @brief The type of the elements contained by the ::ArrayList. Refer to ::spec_t
     */
    spec_t type;

    /**
     * @brief Void pointer to the first element of the ::ArrayList
     */
    void *body;

    /**
     * @brief The number of elements contained by the ::ArrayList
     */
    unsigned int size;
} *ArrayList;

/**
 * @brief ::Node type
 * @details Base component of every linked data type
 * @note All the parameters in this structure must be intended as read-only. Manually modifying them can cause unknown and unwanted behavior
 */
typedef struct node {
    /**
     * @brief Pointer to the value contained
     */
    void *data;

    /**
     * @brief The ::Node this ::Node is linked to
     */
    struct node *linked;
} *Node;

/**
 * @brief ::LinkedList type
 * @note All the parameters in this structure must be intended as read-only. Manually modifying them can cause unknown and unwanted behavior
 */
typedef struct {
    /**
     * @brief The type of the elements contained by the ::LinkedList. Refer to ::spec_t
     */
    spec_t type;

    /**
     * @brief Head of the ::LinkedList
     */
    Node head;

    /**
     * @brief Tail of the ::LinkedList
     */
    Node tail;

    /**
     * @brief The number of elements contained by the ::LinkedList
     */
    unsigned int size;
} *LinkedList;

/**
 * @brief ::Stack type
 * @note All the parameters in this structure must be intended as read-only. Manually modifying them can cause unknown and unwanted behavior
 */
typedef struct {
    /**
     * @brief The type of the elements contained by the ::Stack. Refer to ::spec_t
     */
    spec_t type;

    /**
     * @brief Head of the ::Stack
     */
    Node head;
} *Stack;

/**
 * @brief ::Queue type
 * @note All the parameters in this structure must be intended as read-only. Manually modifying them can cause unknown and unwanted behavior
 */
typedef struct {
    /**
     * @brief The type of the elements contained by the ::Queue. Refer to ::spec_t
     */
    spec_t type;

    /**
     * @brief Head of the ::Queue
     */
    Node head;

    /**
     * @brief Tail of the ::Queue
     */
    Node tail;

    /**
     * @brief The number of elements contained by the ::Queue
     */
    unsigned int size;
} *Queue;

#endif