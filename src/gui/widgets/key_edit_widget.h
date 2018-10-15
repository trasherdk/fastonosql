/*  Copyright (C) 2014-2018 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <QGroupBox>

#include <fastonosql/core/db_key.h>  // for NDbKValue, NValue

class QLineEdit;
class QComboBox;
class QLabel;

namespace fastonosql {
namespace gui {

class FastoViewer;
class FastoEditor;
class HashTypeWidget;
class StreamTypeWidget;
class ListTypeWidget;

class KeyEditWidget : public QGroupBox {
  Q_OBJECT
 public:
  typedef QGroupBox base_class;

  explicit KeyEditWidget(const std::vector<common::Value::Type>& availible_types, QWidget* parent = Q_NULLPTR);

  void initialize(const core::NDbKValue& key);

  virtual ~KeyEditWidget();

  void setEnableKeyEdit(bool key_edit);

  bool getKey(core::NDbKValue* key) const;

 Q_SIGNALS:
  void typeChanged(common::Value::Type type);
  void keyChanged();

 private Q_SLOTS:
  void changeType(int index);

 protected:
  virtual void changeEvent(QEvent* ev) override;

 private:
  void retranslateUi();

  common::Value* createItem() const;
  void syncControls(const core::NValue& item);

  QLabel* type_label_;
  QLabel* key_label_;
  QLineEdit* key_edit_;
  QComboBox* types_combo_box_;
  QLabel* value_label_;
  QLineEdit* value_edit_;
  FastoViewer* json_value_edit_;
  QComboBox* bool_value_edit_;
  ListTypeWidget* value_list_edit_;
  HashTypeWidget* value_table_edit_;
  StreamTypeWidget* stream_table_edit_;
};

}  // namespace gui
}  // namespace fastonosql
