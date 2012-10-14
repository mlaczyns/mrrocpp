/*
 * wgt_servo_algorithm.cpp
 *
 *  Created on: 14-07-2011
 *      Author: matt
 */

#include "wgt_servo_algorithm.h"
#include "mainwindow.h"
#include "ui_robot.h"
#include "interface.h"
#include "ui_r_common_012.h"
#include "allrobots.h"
#include "mp.h"
#include "ui_ecp_robot/ui_ecp_r_common_012.h"

wgt_servo_algorithm::wgt_servo_algorithm(QString _widget_label, mrrocpp::ui::common::Interface& _interface, mrrocpp::ui::common::UiRobot *robo, QWidget *parent) :
		wgt_base(_widget_label, _interface, robo, parent)
{
	robot = dynamic_cast <mrrocpp::ui::common_012::UiRobot *>(robo);
	//ui->setupUi(this);
	dwgt->setWindowTitle(QString::fromStdString((robo->getName())) + " sa");
}

wgt_servo_algorithm::~wgt_servo_algorithm()
{
	// TODO Auto-generated destructor stub
}

void wgt_servo_algorithm::setup_ui(QGridLayout *layout, int _rows_number)
{
	/*
	 wgt_base::setup_ui(layout, _rows_number);

	 create_buttons_and_spin_boxes();

	 for (int i = 0; i < rows_number; i++) {
	 gridLayout->addWidget(create_label_to_vector(axis_labels), i + 1, 0, 1, 1);
	 }

	 create_buttons();

	 wgt_base::create_buttons_and_spin_boxes(desired_pos_column, inc_move_column, rows_number);
	 */
}

void wgt_servo_algorithm::create_buttons_and_spin_boxes()
{
	for (int i = 0; i < rows_number; i++)
		add_current_position_spin_box(create_spin_box_to_vector(current_pos_spin_boxes), i);
}

void wgt_servo_algorithm::add_current_position_spin_box(QDoubleSpinBox *spin_box, int row)
{
	gridLayout->addWidget(spin_box, row + 1, 1, 1, 1);
}

void wgt_servo_algorithm::create_buttons()
{

	copy_button = add_button(">", 1, 3, rows_number, 1);
	connect(copy_button, SIGNAL(clicked()), this, SLOT(copy_button_clicked()), Qt::QueuedConnection);

}

void wgt_servo_algorithm::synchro_depended_widgets_disable(bool set_disabled)
{
	copy_button->setDisabled(set_disabled);
	//ui.pushButton_execute->setDisabled(set_disabled);
	ui->pushButton_read->setDisabled(set_disabled);
//	ui.pushButton_import->setDisabled(set_disabled);
	//ui.pushButton_export->setDisabled(set_disabled);

	for (int i = 0; i < rows_number; i++) {
		current_pos_spin_boxes[i]->setDisabled(set_disabled);
		desired_pos_spin_boxes[i]->setDisabled(set_disabled);
	}

}

void wgt_servo_algorithm::inc_move_left_button_clicked(int button)
{
	get_desired_position();
//	robot->desired_pos[button] -= ui.doubleSpinBox_step->value();
	move_it();
}

void wgt_servo_algorithm::inc_move_right_button_clicked(int button)
{
	get_desired_position();
	//robot->desired_pos[button] += ui.doubleSpinBox_step->value();
	move_it();
}

void wgt_servo_algorithm::on_pushButton_read_clicked()
{
	printf("read\n");
	init();
}

void wgt_servo_algorithm::on_pushButton_import_clicked()
{
	double val[rows_number];

	for (int i = 0; i < rows_number; i++)
		val[i] = 0.0;

	interface.get_main_window()->get_lineEdit_position(val, rows_number);

	for (int i = 0; i < rows_number; i++)
		desired_pos_spin_boxes[i]->setValue(val[i]);
}

void wgt_servo_algorithm::on_pushButton_export_clicked()
{
	std::stringstream buffer(std::stringstream::in | std::stringstream::out);

	buffer << widget_label.toStdString() << " POSITION\n ";
	for (int i = 0; i < rows_number; i++)
		buffer << " " << desired_pos_spin_boxes[i]->value();

	interface.ui_msg->message(buffer.str());
}

void wgt_servo_algorithm::init_and_copy_slot()
{
	init();
	copy();
}

void wgt_servo_algorithm::copy_button_clicked()
{
	copy();
}

int wgt_servo_algorithm::copy()
{

	if (robot->state.edp.pid != -1) {
		if (robot->state.edp.is_synchronised) // Czy robot jest zsynchronizowany?
		{
			//	ui.pushButton_execute->setDisabled(false);
			for (int i = 0; i < rows_number; i++) {
				desired_pos_spin_boxes[i]->setValue(current_pos_spin_boxes[i]->value());
			}
		} else {
			//	ui.pushButton_execute->setDisabled(true); // Wygaszanie elementow przy niezsynchronizowanym robocie
		}
	}

	return 1;
}

void wgt_servo_algorithm::on_pushButton_execute_clicked()
{
	get_desired_position();
	move_it();
}

