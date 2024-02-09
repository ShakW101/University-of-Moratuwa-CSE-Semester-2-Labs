#include <SFML/Graphics.hpp>
#include <algorithm> // For std::minmax_element

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Graph");

    // Define data arrays for the first data set (replace with your actual data)
    float xValues[] = {3, 5, 7, 9, 11, 13, 15, 17,19, 21 , 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
    float yValues[] = {4.2504, 7.9416, 12.1002, 16.7752, 21.8666, 25.55, 29.9168, 34.8584, 40.8498, 45.7002, 49.7084, 56.0254, 59.7752, 63.3834, 68.1914, 74.2832, 80.1168, 88.0248, 92.8082, 97.5834, 102.3, 106.175, 112.558, 116.225};
    size_t numPoints = sizeof(xValues) / sizeof(xValues[0]);

    // Define data arrays for the second data set (replace with your actual data)
    float xValues2[] = {3, 5, 7, 9, 11, 13, 15, 17,19, 21 , 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49};
    float yValues2[] = {0.8252, 1.2084, 1.8172, 2.575, 3.75, 4.3, 5.125, 6.15, 7.9332, 8.675, 9.7084, 11.8416, 12.742, 13.3584, 14.7584, 16.3748, 20.9416, 22.8914, 22.2664, 23.4584, 25.7502, 28.6082, 30.1, 31.55};
    size_t numPoints2 = sizeof(xValues2) / sizeof(xValues2[0]);

    // Find the minimum and maximum values for both data sets
    auto [minX, maxX] = std::minmax_element(std::begin(xValues), std::end(xValues));
    auto [minY, maxY] = std::minmax_element(std::begin(yValues), std::end(yValues));
    auto [minX2, maxX2] = std::minmax_element(std::begin(xValues2), std::end(xValues2));
    auto [minY2, maxY2] = std::minmax_element(std::begin(yValues2), std::end(yValues2));

    // Calculate the range for x and y coordinates for both data sets
    float xRange = std::max(*maxX, *maxX2) - std::min(*minX, *minX2);
    float yRange = std::max(*maxY, *maxY2) - std::min(*minY, *minY2);

    // Calculate the center and size of the view
    float viewCenterX = ((*minX + *maxX) / 2.0f + (*minX2 + *maxX2) / 2.0f) / 2.0f;
    float viewCenterY = ((*minY + *maxY) / 2.0f + (*minY2 + *maxY2) / 2.0f) / 2.0f;
    float viewWidth = std::max(xRange * 1.1f, 1.0f); // Add some padding
    float viewHeight = std::max(yRange * 1.1f, 1.0f); // Add some padding

    // Create the SFML view
    sf::View view(sf::FloatRect(-5, -5, 70, 150));
    window.setView(view);

    // Create the x and y axes
    sf::VertexArray axes(sf::Lines, 4);
    // x-axis
    axes[0].position = sf::Vector2f(std::min(*minX, *minX2), viewHeight);
    axes[1].position = sf::Vector2f(std::max(*maxX, *maxX2), viewHeight);
    // y-axis
    axes[2].position = sf::Vector2f(0, std::max(*maxY, *maxY2));
    axes[3].position = sf::Vector2f(0, std::min(*minY, *minY2));
    // Set color for both axes
    for (int i = 0; i < 4; ++i) {
        axes[i].color = sf::Color::Black;
    }

    // Create markings for x-axis
    sf::VertexArray xMarkings(sf::Lines);
    for (float x = std::floor(std::min(*minX, *minX2)); x <= std::max(*maxX, *maxX2); x += 1.0f) {
        float xPos = (x - std::min(*minX, *minX2)) / xRange * viewWidth;
        xMarkings.append(sf::Vertex(sf::Vector2f(xPos, viewHeight), sf::Color::Black));
        xMarkings.append(sf::Vertex(sf::Vector2f(xPos, viewHeight - 0.2f), sf::Color::Black));
    }


    // Create markings for y-axis
    sf::VertexArray yMarkings(sf::Lines);
    for (float y = std::floor(std::min(*minY, *minY2)); y <= std::max(*maxY, *maxY2); y += 1.0f) {
        float yPos = viewHeight - (y - std::min(*minY, *minY2)) / yRange * viewHeight;
        yMarkings.append(sf::Vertex(sf::Vector2f(0, yPos), sf::Color::Black));
        yMarkings.append(sf::Vertex(sf::Vector2f(-0.2f, yPos), sf::Color::Black));
    }



    // Create points for the first data set
    sf::VertexArray graph(sf::LineStrip);
    for (size_t i = 0; i < numPoints; ++i) {
        float x = (xValues[i] - std::min(*minX, *minX2)) / xRange * viewWidth;
        float y = viewHeight - (yValues[i] - std::min(*minY, *minY2)) / yRange * viewHeight;
        graph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Red)); // Adjust point color
    }

    // Create points for the second data set
    sf::VertexArray graph2(sf::LineStrip);
    for (size_t i = 0; i < numPoints2; ++i) {
        float x = (xValues2[i] - std::min(*minX, *minX2)) / xRange * viewWidth;
        float y = viewHeight - (yValues2[i] - std::min(*minY, *minY2)) / yRange * viewHeight;
        graph2.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue)); // Adjust point color
    }

    // Main loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the axes
        window.draw(axes);

        // Draw the x-axis markings
        window.draw(xMarkings);

        // Draw the y-axis markings
        window.draw(yMarkings);



        // Draw the first graph
        window.draw(graph);

        // Draw the second graph
        window.draw(graph2);

        // Display the window
        window.display();
    }

    return 0;
}
