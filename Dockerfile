FROM ultralytics/ultralytics:latest-jetson-jetpack6

WORKDIR /workspace

ENV DEBIAN_FRONTEND=noninteractive

# Install ROS 2 Humble and cv_bridge.
RUN apt-get update && apt-get install -y --no-install-recommends \
	locales \
	software-properties-common \
	curl \
	ca-certificates \
	gnupg2 \
	lsb-release \
	&& locale-gen en_US en_US.UTF-8 \
	&& update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 \
	&& add-apt-repository universe \
	&& curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
		-o /usr/share/keyrings/ros-archive-keyring.gpg \
	&& echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" \
		> /etc/apt/sources.list.d/ros2.list \
	&& apt-get update && apt-get install -y --no-install-recommends \
		ros-humble-ros-base \
		ros-humble-cv-bridge \
	&& rm -rf /var/lib/apt/lists/*

ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

COPY . .

RUN pip3 install -r requirements.txt colcon-common-extensions

# Build custom ROS2 messages.
RUN . /opt/ros/humble/setup.sh \
    && mkdir -p /ros2_ws/src \
    && cp -r robot_msgs /ros2_ws/src/ \
    && cd /ros2_ws \
    && colcon build --packages-select robot_msgs

RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc \
    && echo "source /ros2_ws/install/setup.bash" >> /root/.bashrc

CMD ["/bin/bash"]
